#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/sha.h>
#include <openssl/rsa.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <chrono>
using namespace std;

bool key_gen(const char *filePrivate, const char *filePublic, const char *format, const int keysize) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    RSA *rsa = RSA_new();
    BIGNUM *bne = BN_new();
    if (!BN_set_word(bne, RSA_F4) || !RSA_generate_key_ex(rsa, keysize, bne, NULL)) {
        cerr << "Failed to generate RSA key pair." << endl;
        RSA_free(rsa);
        BN_free(bne);
        return false;
    }

    FILE *privateFile = fopen(filePrivate, "wb");
    FILE *publicFile = fopen(filePublic, "wb");
    if (!privateFile || !publicFile) {
        cerr << "Failed to open key files." << endl;
        RSA_free(rsa);
        BN_free(bne);
        if (privateFile) fclose(privateFile);
        if (publicFile) fclose(publicFile);
        return false;
    }

    bool success = false;
    string strFormat(format);
    if (strFormat == "DER") {
        success = i2d_RSAPrivateKey_fp(privateFile, rsa) && i2d_RSAPublicKey_fp(publicFile, rsa);
    } else if (strFormat == "PEM") {
        success = PEM_write_RSAPrivateKey(privateFile, rsa, NULL, NULL, 0, NULL, NULL) &&
                  PEM_write_RSA_PUBKEY(publicFile, rsa);
    } else {
        cerr << "Unknown format specified." << endl;
    }

    fclose(privateFile);
    fclose(publicFile);
    RSA_free(rsa);
    BN_free(bne);
    return success;
}

int sign(const char *filePrivate, const char *filename, const char *signFile) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    BIO *bio = BIO_new_file(filePrivate, "rb");
    if (!bio) {
        cerr << "Failed to open private key file." << endl;
        return 1;
    }

    RSA *rsa = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    if (!rsa) rsa = d2i_RSAPrivateKey_bio(bio, NULL);
    BIO_free(bio);
    if (!rsa) {
        cerr << "Failed to read private key." << endl;
        return 2;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    try {
        ifstream inFile(filename, ios::binary);
        vector<unsigned char> fileContents((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
        SHA256(&fileContents[0], fileContents.size(), hash);
    } catch (...) {
        cerr << "Failed to read file." << endl;
        RSA_free(rsa);
        return 3;
    }

    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey, rsa);
    EVP_MD_CTX *mdCtx = EVP_MD_CTX_new();
    EVP_PKEY_CTX *pkeyCtx = NULL;

    if (EVP_DigestSignInit(mdCtx, &pkeyCtx, EVP_sha256(), NULL, pkey) <= 0 ||
        EVP_PKEY_CTX_set_rsa_padding(pkeyCtx, RSA_PKCS1_PSS_PADDING) <= 0 ||
        EVP_DigestSignUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH) <= 0) {
        cerr << "Failed to initialize signing context." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 4;
    }

    size_t sigLen = 0;
    if (EVP_DigestSignFinal(mdCtx, NULL, &sigLen) <= 0) {
        cerr << "Failed to get signature length." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 5;
    }

    vector<unsigned char> signature(sigLen);
    if (EVP_DigestSignFinal(mdCtx, signature.data(), &sigLen) <= 0) {
        cerr << "Failed to generate signature." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 6;
    }

    ofstream outFile(signFile, ios::binary);
    outFile.write(reinterpret_cast<const char *>(signature.data()), sigLen);

    EVP_PKEY_free(pkey);
    EVP_MD_CTX_free(mdCtx);
    return 0;
}

int verify(const char *filePublic, const char *filename, const char *signFile) {
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    BIO *bio = BIO_new_file(filePublic, "rb");
    if (!bio) {
        cerr << "Failed to open public key file." << endl;
        return 1;
    }

    RSA *rsa = PEM_read_bio_RSA_PUBKEY(bio, NULL, NULL, NULL);
    if (!rsa) {
        BIO_reset(bio);
        rsa = PEM_read_bio_RSAPublicKey(bio, NULL, NULL, NULL);
    }
    if (!rsa) {
        BIO_reset(bio);
        rsa = d2i_RSA_PUBKEY_bio(bio, NULL);
        if (!rsa) {
            BIO_reset(bio);
            rsa = d2i_RSAPublicKey_bio(bio, NULL);
        }
    }
    BIO_free(bio);
    if (!rsa) {
        cerr << "Failed to read public key." << endl;
        return 2;
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    try {
        ifstream inFile(filename, ios::binary);
        vector<unsigned char> fileContents((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
        SHA256(&fileContents[0], fileContents.size(), hash);
    } catch (...) {
        cerr << "Failed to read file." << endl;
        RSA_free(rsa);
        return 3;
    }

    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_PKEY_assign_RSA(pkey, rsa);
    EVP_MD_CTX *mdCtx = EVP_MD_CTX_new();
    EVP_PKEY_CTX *pkeyCtx = NULL;

    if (EVP_DigestVerifyInit(mdCtx, &pkeyCtx, EVP_sha256(), NULL, pkey) <= 0 ||
        EVP_PKEY_CTX_set_rsa_padding(pkeyCtx, RSA_PKCS1_PSS_PADDING) <= 0 ||
        EVP_DigestVerifyUpdate(mdCtx, hash, SHA256_DIGEST_LENGTH) <= 0) {
        cerr << "Failed to initialize verification context." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 4;
    }

    ifstream sigFile(signFile, ios::binary);
    if (!sigFile.is_open()) {
        cerr << "Failed to open signature file." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 5;
    }

    sigFile.seekg(0, ios::end);
    size_t sigLen = sigFile.tellg();
    sigFile.seekg(0, ios::beg);
    vector<unsigned char> signature(sigLen);
    sigFile.read(reinterpret_cast<char *>(&signature[0]), sigLen);

    int verifyResult = EVP_DigestVerifyFinal(mdCtx, signature.data(), sigLen);
    if (verifyResult != 1) {
        cerr << "Signature verification failed." << endl;
        EVP_PKEY_free(pkey);
        EVP_MD_CTX_free(mdCtx);
        return 6;
    }

    EVP_PKEY_free(pkey);
    EVP_MD_CTX_free(mdCtx);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage:" << endl;
        cerr << "\tkeygen <private_key_file> <public_key_file> <format (PEM/DER)> <key size>" << endl;
        cerr << "\tsign <private_key_file> <input_file> <signature_file>" << endl;
        cerr << "\tverify <public_key_file> <input_file> <signature_file>" << endl;
        return -1;
    }

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    string command = argv[1];
    if (command == "keygen") {
        if (argc != 6) {
            cerr << "Usage: keygen <private_key_file> <public_key_file> <format (PEM/DER)> <key size>" << endl;
            return -1;
        }
        if (key_gen(argv[2], argv[3], argv[4], stoi(argv[5]))) {
            cout << "Key generation successful." << endl;
        } else {
            cerr << "Key generation failed." << endl;
            return -1;
        }
    } else if (command == "sign") {
        if (argc != 5) {
            cerr << "Usage: sign <private_key_file> <input_file> <signature_file>" << endl;
            return -1;
        }
        int result ;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=0 ; i<1000; i++)
        {
            result =  sign(argv[2], argv[3], argv[4]);
        }
         auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(stop - start);
        cout << "\nVerification time: " << duration.count() / 1000 << " milliseconds" << endl;
        
        if (result == 0) {
            cout << "Signing successful." << endl;
        } else {
            cerr << "Signing failed with error code: " << result << endl;
            return -1;
        }
    } else if (command == "verify") {
        if (argc != 5) {
            cerr << "Usage: verify <public_key_file> <input_file> <signature_file>" << endl;
            return -1;
        }
        int result ;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i=0 ; i<1000; i++)
        {
            result = verify(argv[2], argv[3], argv[4]);
        }
         auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration<double, std::milli>(stop - start);
        cout << "\nVerification time: " << duration.count() / 1000 << " milliseconds" << endl;
      
        if (result == 0) {
            cout << "Signature verification successful." << endl;
        } else {
            cerr << "Signature verification failed with error code: " << result << endl;
            return -1;
        }
    } else {
        cerr << "Unknown command: " << command << endl;
        return -1;
    }

    ERR_free_strings();
    EVP_cleanup();
    return 0;
}
