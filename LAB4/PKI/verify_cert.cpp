#include <openssl/bio.h>
#include <openssl/x509.h>
#include <openssl/pem.h>
#include <iostream>
#include <fstream>
#include <openssl/err.h>

// #ifndef DLL_EXPORT 
// #ifdef _WIN32 
// #define DLL_EXPORT __declspec(dllexport) 
// #else 
// #define DLL_EXPORT 
// #endif 
// #endif 

// extern "C" { 

// DLL_EXPORT bool verifyCertificate(const char *chrprivateKeyPath,const char *chrpdfPath,const char *chrsignaturePath); 

// DLL_EXPORT bool verifySignature(const char *chrpublicKeyPath,const char *chrpdfPath,const char *chrsignaturePath); 
// }

// Hàm xác thực chứng chỉ
bool verifyCertificate(X509* cert, STACK_OF(X509)* intermediateCerts, X509_STORE* store) {
    // Tạo context xác thực
    X509_STORE_CTX* ctx = X509_STORE_CTX_new();
    if (ctx == nullptr) {
        std::cerr << "Error: Cannot create verification context." << std::endl;
        return false;
    }
    if (!X509_STORE_CTX_init(ctx, store, cert, intermediateCerts)) {
        std::cerr << "Error: Cannot initialize verification context." << std::endl;
        X509_STORE_CTX_free(ctx);
        return false;
    }
    // Xác thực chứng chỉ
    int result = X509_verify_cert(ctx);
    X509_STORE_CTX_free(ctx);
    return result == 1;
}

// Hàm in khóa công khai của chủ thể dưới dạng HEX
void printPublicKeyHex(X509* cert, std::ostream& outStream) {
    EVP_PKEY* pubKey = X509_get_pubkey(cert);
    if (pubKey) {
        outStream << "Subject Public Key Info:" << std::endl;
        int keyType = EVP_PKEY_id(pubKey);
        outStream << "  Public Key Algorithm: " << OBJ_nid2ln(keyType) << std::endl;
        int keyBits = EVP_PKEY_bits(pubKey);
        outStream << "  Public-Key: " << keyBits << " bits" << std::endl;

        // In khóa công khai dưới dạng HEX
        BIO* bio = BIO_new(BIO_s_mem());
        if (bio == nullptr) {
            EVP_PKEY_free(pubKey);
            outStream << "Error: Cannot create BIO buffer." << std::endl;
            return;
        }

        if (PEM_write_bio_PUBKEY(bio, pubKey) != 1) {
            BIO_free(bio);
            EVP_PKEY_free(pubKey);
            outStream << "Error: Cannot write public key." << std::endl;
            return;
        }

        BUF_MEM* bptr;
        BIO_get_mem_ptr(bio, &bptr);

        for (size_t i = 0; i < bptr->length; ++i) {
            printf("%02X", static_cast<unsigned char>(bptr->data[i]));
            if (i < bptr->length - 1) {
                if ((i + 1) % 15 == 0) {
                    std::cout << std::endl;
                } else {
                    std::cout << ":";
                }
            }
        }

        outStream << std::endl;

        BIO_free(bio);
        EVP_PKEY_free(pubKey);
    } else {
        outStream << "Failed to retrieve the public key." << std::endl;
    }
}
X509* readCertificate(const std::string& filePath, const std::string& mode) {
    BIO* bio = BIO_new_file(filePath.c_str(), "r");
    if (!bio) {
        std::cerr << "Error: Cannot open file " << filePath << std::endl;
        ERR_print_errors_fp(stderr);
        return nullptr;
    }

    X509* cert = nullptr;
    if (mode == "PEM") {
        cert = PEM_read_bio_X509(bio, nullptr, nullptr, nullptr);
    } else if (mode == "DER") {
        cert = d2i_X509_bio(bio, nullptr);
    } else {
        std::cerr << "Error: Unsupported mode " << mode << std::endl;
    }

    if (!cert) {
        std::cerr << "Error: Cannot read certificate from file." << std::endl;
    }
    BIO_free(bio);
    return cert;
}
/// Main function to verify and output certificates
void verifyAndOutputCertificates(const std::string& mode, const std::string& RootCACert, const std::string& IntermediateCert, const std::string& WebsiteCert) {
    OpenSSL_add_all_algorithms();
    ERR_load_BIO_strings();
    ERR_load_crypto_strings();

    // Load Root CA certificate
    X509* rootCACert = readCertificate(RootCACert, mode);
    if (!rootCACert) return;

    // Load Intermediate certificate
    X509* intermediateCert = readCertificate(IntermediateCert, mode);
    if (!intermediateCert) {
        X509_free(rootCACert);
        return;
    }
    STACK_OF(X509)* intermediateCerts = sk_X509_new_null();
    sk_X509_push(intermediateCerts, intermediateCert);

    // Load Website certificate
    X509* websiteCert = readCertificate(WebsiteCert, mode);
    if (!websiteCert) {
        sk_X509_pop_free(intermediateCerts, X509_free);
        X509_free(rootCACert);
        return;
    }

    // Create certificate store and add Root CA certificate
    X509_STORE* store = X509_STORE_new();
    if (!store) {
        std::cerr << "Error: Cannot create certificate store." << std::endl;
        sk_X509_pop_free(intermediateCerts, X509_free);
        X509_free(rootCACert);
        X509_free(websiteCert);
        return;
    }
    X509_STORE_add_cert(store, rootCACert);

    // Verify the Website certificate
    bool isValid = verifyCertificate(websiteCert, intermediateCerts, store);

    // Print the result
    if (isValid) {
        std::cout << "Website certificate is valid." << std::endl;
        std::cout << "Subject Name: " << X509_NAME_oneline(X509_get_subject_name(websiteCert), nullptr, 0) << std::endl;
        std::cout << "Issuer Name: " << X509_NAME_oneline(X509_get_issuer_name(websiteCert), nullptr, 0) << std::endl;
        printPublicKeyHex(websiteCert, std::cout);
    } else {
        std::cerr << "Website certificate verification failed." << std::endl;
    }

    // Free memory
    sk_X509_pop_free(intermediateCerts, X509_free);
    X509_free(rootCACert);
    X509_free(websiteCert);
    X509_STORE_free(store);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <mode> <RootCAFilePath> <IntermediateFilePath> <WebsiteFilePath>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string RootCACert = argv[2];
    std::string IntermediateCert = argv[3];
    std::string WebsiteCert = argv[4];

    verifyAndOutputCertificates(mode, RootCACert, IntermediateCert, WebsiteCert);

    return 0;
}