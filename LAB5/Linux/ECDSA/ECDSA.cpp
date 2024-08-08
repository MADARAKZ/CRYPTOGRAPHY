#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/bio.h>
#include <openssl/provider.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
using namespace std;
using std::runtime_error;

#ifdef BUILD_DLL
#define EXPORT __attribute__((visibility("default")))
#else
#define EXPORT
#endif

#ifndef DLL_EXPORT
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
#endif

extern "C"
{
    DLL_EXPORT bool genECCKeyPair(const char *privateKeyPath, const char *publicKeyPath, const char *mode);
    DLL_EXPORT bool signPdf(const char *chrprivateKeyPath, const char *chrpdfPath, const char *chrsignaturePath, const char *mode);
    DLL_EXPORT bool verifySignature(const char *chrpublicKeyPath, const char *chrpdfPath, const char *chrsignaturePath, const char *mode);
}

bool genECCKeyPair(const char *privateKeyPath, const char *publicKeyPath, const char *mode)
{
    std::string strMode(mode);

    EVP_PKEY_CTX *pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
    if (!pctx)
    {
        std::cerr << "Error creating context." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    if (EVP_PKEY_keygen_init(pctx) <= 0)
    {
        std::cerr << "Error initializing keygen context." << std::endl;
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    if (EVP_PKEY_CTX_set_ec_paramgen_curve_nid(pctx, NID_X9_62_prime256v1) <= 0)
    {
        std::cerr << "Error setting curve." << std::endl;
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    EVP_PKEY *pkey = NULL;
    if (EVP_PKEY_keygen(pctx, &pkey) <= 0)
    {
        std::cerr << "Error generating key." << std::endl;
        ERR_print_errors_fp(stderr);
        EVP_PKEY_CTX_free(pctx);
        return false;
    }

    EVP_PKEY_CTX_free(pctx);

    if (strMode == "PEM")
    {
        // Write private key to PEM
        BIO *privBio = BIO_new_file(privateKeyPath, "w");
        if (!PEM_write_bio_PrivateKey(privBio, pkey, NULL, NULL, 0, NULL, NULL))
        {
            std::cerr << "Error writing private key to PEM." << std::endl;
            ERR_print_errors_fp(stderr);
            BIO_free(privBio);
            EVP_PKEY_free(pkey);
            return false;
        }
        BIO_free(privBio);

        // Write public key to PEM
        BIO *pubBio = BIO_new_file(publicKeyPath, "w");
        if (!PEM_write_bio_PUBKEY(pubBio, pkey))
        {
            std::cerr << "Error writing public key to PEM." << std::endl;
            ERR_print_errors_fp(stderr);
            BIO_free(pubBio);
            EVP_PKEY_free(pkey);
            return false;
        }
        BIO_free(pubBio);
    }
    else if (strMode == "DER")
    {
        std::ofstream privateKeyBin(privateKeyPath, std::ios::binary);
        if (!privateKeyBin.is_open())
        {
            std::cerr << "Error opening private key binary file." << std::endl;
            EVP_PKEY_free(pkey);
            return false;
        }

        int privateKeyLen = i2d_PrivateKey(pkey, NULL);
        unsigned char *privateKeyBuf = (unsigned char *)OPENSSL_malloc(privateKeyLen);
        unsigned char *temp = privateKeyBuf;
        privateKeyLen = i2d_PrivateKey(pkey, &temp);
        privateKeyBin.write(reinterpret_cast<const char *>(privateKeyBuf), privateKeyLen);
        privateKeyBin.close();
        OPENSSL_free(privateKeyBuf);

        // Write public key to binary file
        std::ofstream publicKeyBin(publicKeyPath, std::ios::binary);
        if (!publicKeyBin.is_open())
        {
            std::cerr << "Error opening public key binary file." << std::endl;
            EVP_PKEY_free(pkey);
            return false;
        }

        int publicKeyLen = i2d_PUBKEY(pkey, NULL);
        unsigned char *publicKeyBuf = (unsigned char *)OPENSSL_malloc(publicKeyLen);
        unsigned char *tempPub = publicKeyBuf;
        publicKeyLen = i2d_PUBKEY(pkey, &tempPub);
        publicKeyBin.write(reinterpret_cast<const char *>(publicKeyBuf), publicKeyLen);
        publicKeyBin.close();
        OPENSSL_free(publicKeyBuf);
    }

    EVP_PKEY_free(pkey);
    return true;
}

bool signPdf(const char *chrprivateKeyPath, const char *chrpdfPath, const char *chrsignaturePath, const char *mode)
{
    std::string privateKeyPath(chrprivateKeyPath), pdfPath(chrpdfPath), signaturePath(chrsignaturePath), strMode(mode);

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Read the private key
    EVP_PKEY *privateKey = NULL;
    BIO *keyData = BIO_new_file(privateKeyPath.c_str(), "rb");

    if (strMode == "PEM")
    {
        privateKey = PEM_read_bio_PrivateKey(keyData, NULL, NULL, NULL);
    }
    else if (strMode == "DER")
    {
        privateKey = d2i_PrivateKey_bio(keyData, NULL);
    }

    BIO_free(keyData);

    if (!privateKey)
    {
        std::cerr << "Error reading private key." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Create a buffer to hold the document hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    std::ifstream pdfFile(pdfPath, std::ios::binary);

    if (!pdfFile.is_open())
    {
      
        EVP_PKEY_free(privateKey);
        return false;
    }

    std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
    pdfFile.close();

    // Hash the PDF
    SHA256(&pdfContents[0], pdfContents.size(), hash);

    // Sign the hash
    EVP_MD_CTX *messageData = EVP_MD_CTX_new();
    EVP_SignInit(messageData, EVP_sha256());
    EVP_SignUpdate(messageData, hash, SHA256_DIGEST_LENGTH);

    unsigned int signatureLen = EVP_PKEY_size(privateKey);
    std::vector<unsigned char> signature(signatureLen);

    if (!EVP_SignFinal(messageData, &signature[0], &signatureLen, privateKey))
    {
        std::cerr << "Error signing PDF." << std::endl;
        EVP_MD_CTX_free(messageData);
        EVP_PKEY_free(privateKey);
        return false;
    }

    EVP_MD_CTX_free(messageData);
    EVP_PKEY_free(privateKey);

    // Write the signature to a file
    std::ofstream signatureFile(signaturePath, std::ios::binary);

    if (!signatureFile.is_open())
    {
        std::cerr << "Error opening signature file." << std::endl;
        return false;
    }

    signatureFile.write(reinterpret_cast<const char *>(&signature[0]), signatureLen);
    signatureFile.close();

    EVP_cleanup();
    ERR_free_strings();

    return true;
}

bool verifySignature(const char *chrpublicKeyPath, const char *chrpdfPath, const char *chrsignaturePath, const char *mode)
{
    std::string publicKeyPath(chrpublicKeyPath), pdfPath(chrpdfPath), signaturePath(chrsignaturePath), strMode(mode);

    // Load the public key using BIO
    EVP_PKEY *publicKey = NULL;
    BIO *pubData = BIO_new_file(publicKeyPath.c_str(), "rb");

    if (strMode == "PEM")
    {
        publicKey = PEM_read_bio_PUBKEY(pubData, NULL, NULL, NULL);
    }
    else if (strMode == "DER")
    {
        publicKey = d2i_PUBKEY_bio(pubData, NULL);
    }

    BIO_free(pubData);

    if (!publicKey)
    {
        std::cerr << "Error reading public key." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }

    // Read the PDF
    std::ifstream pdfFile(pdfPath, std::ios::binary);

    if (!pdfFile.is_open())
    {
        std::cerr << "Error opening PDF file." << std::endl;
        EVP_PKEY_free(publicKey);
        return false;
    }

    std::vector<unsigned char> pdfContents((std::istreambuf_iterator<char>(pdfFile)), std::istreambuf_iterator<char>());
    pdfFile.close();

    // Hash the PDF
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(&pdfContents[0], pdfContents.size(), hash);

    // Read the signature
    std::ifstream signatureFile(signaturePath, std::ios::binary);

    if (!signatureFile.is_open())
    {
        std::cerr << "Error opening signature file." << std::endl;
        EVP_PKEY_free(publicKey);
        return false;
    }

    std::vector<unsigned char> signature((std::istreambuf_iterator<char>(signatureFile)), std::istreambuf_iterator<char>());
    signatureFile.close();

    // Verify the signature
    EVP_MD_CTX *messageData = EVP_MD_CTX_new();
    EVP_VerifyInit(messageData, EVP_sha256());
    EVP_VerifyUpdate(messageData, hash, SHA256_DIGEST_LENGTH);

    int verificationResult = EVP_VerifyFinal(messageData, &signature[0], signature.size(), publicKey);

    EVP_MD_CTX_free(messageData);
    EVP_PKEY_free(publicKey);

    if (verificationResult == 1)
    {
        return true;
    }
    else if (verificationResult == 0)
    {
        return false;
    }
    else
    {
        std::cerr << "Error during signature verification." << std::endl;
        ERR_print_errors_fp(stderr);
        return false;
    }
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [sign|verify|genkey] [other parameters]" << std::endl;
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "sign")
    {
        if (argc != 6)
        {
            std::cerr << "Usage: " << argv[0] << " sign <mode> <private key file> <PDF file> <signature output file>" << std::endl;
            return 1;
        }

        const char *signMode = argv[2];
        const char *privateKeyPath = argv[3];
        const char *pdfPath = argv[4];
        const char *signaturePath = argv[5];
        bool sign;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=0; i<1000; i++)
        {
            sign = signPdf(privateKeyPath, pdfPath, signaturePath, signMode);

        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(stop - start);
        if (sign)
        {
           
            std::cout << "PDF signed successfully." << std::endl;
            cout << "\n----------------------------------------------------------" << endl;
            cout << "Overview ECDSA Sign File Test" << endl;
            cout << "\nSign time: " << duration.count() /1000 << " milliseconds" << endl;
            cout << "----------------------------------------------------------" << endl;
        }
        else
        {
            std::cout << "Failed to sign PDF." << std::endl;
        }
    }
    else if (mode == "verify")
    {
        if (argc != 6)
        {
            std::cerr << "Usage: " << argv[0] << " verify <mode> <public key file> <PDF file> <signature file>" << std::endl;
            return 1;
        }

        const char *verifyMode = argv[2];
        const char *publicKeyPath = argv[3];
        const char *pdfPath = argv[4];
        const char *signaturePath = argv[5];
         bool verify;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=0; i<1000; i++)
        {
            verify = verifySignature(publicKeyPath, pdfPath, signaturePath, verifyMode);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(stop - start);

        if (verify)
        {
            std::cout << "PDF verified successfully." << std::endl;
            cout << "\n----------------------------------------------------------" << endl;
            cout << "Overview ECDSA Verification Test" << endl;
            cout << "\nVerification time: " << duration.count() / 1000 << " milliseconds" << endl;
            cout << "----------------------------------------------------------" << endl;
        }
        else
        {
            std::cout << "Failed to verify PDF." << std::endl;
        }
    }
    else if (mode == "genkey")
    {
        if (argc != 5)
        {
            std::cerr << "Usage: " << argv[0] << " genkey <mode> <private key PEM file> <public key PEM file> " << std::endl;
            return 1;
        }
        const char *keyMode = argv[2];
        const char *privateKeyPemPath = argv[3];
        const char *publicKeyPemPath = argv[4];

        if (genECCKeyPair(privateKeyPemPath, publicKeyPemPath, keyMode))
        {
            std::cout << "ECC key pair generated successfully." << std::endl;
        }
        else
        {
            std::cout << "Failed to generate ECC key pair." << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid mode." << std::endl;
        return 1;
    }

    return 0;
}
