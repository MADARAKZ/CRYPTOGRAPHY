#include "cryptopp/integer.h"
// C/C++ libraries
#include <iostream>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
#include <string>
using std::exit;
#include <cstdlib>
using std::string;

  // header part
	#ifdef _WIN32
	#include <windows.h>
	#endif
	#include <cstdlib>
	#include <locale>
	#include <cctype>

//Cryptopp libraries

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;
//base64
#include "cryptopp/base64.h"

using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::PK_DecryptorFilter;



/* Integer arithmatics*/
#include <cryptopp/integer.h>
using CryptoPP::Integer;

#include <cryptopp/nbtheory.h>
using CryptoPP::ModularSquareRoot;

#include <cryptopp/modarith.h>
using CryptoPP::ModularArithmetic;
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <stdexcept>
using std::runtime_error;

#include <cryptopp/queue.h> 
using CryptoPP::ByteQueue;

#include <cryptopp/files.h>
using CryptoPP::FileSource;
using CryptoPP::FileSink;


#include "cryptopp/rsa.h"
using CryptoPP::RSA;

#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

#include "cryptopp/hex.h"
using CryptoPP::HexDecoder;
using CryptoPP::HexEncoder;

#include <cryptopp/cryptlib.h>
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;
using CryptoPP::BufferedTransformation;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;


// them vo ba cai nay de lam encode decode
#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "cryptopp/rsa.h"
using CryptoPP::RSA;
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSAES_OAEP_SHA_Encryptor;
using CryptoPP::RSAES_OAEP_SHA_Decryptor;

using namespace CryptoPP;
using namespace std;

// Save (BER-BIN) key to file
void Save(const string& filename, const BufferedTransformation& bt);
void SavePrivateKey(const string& filename, const PrivateKey& key);
void SavePublicKey(const string& filename, const PublicKey& key);

// Save (BER)
void SaveBase64(const string& filename, const BufferedTransformation& bt);
void SaveBase64PrivateKey(const string& filename, const PrivateKey& key);
void SaveBase64PublicKey(const string& filename, const PublicKey& key);

void Load(const string& filename, BufferedTransformation& bt);
void LoadPrivateKey(const string& filename, PrivateKey& key);
void LoadPublicKey(const string& filename, PublicKey& key);

// Load BER_BASE64
void LoadBase64(const string& filename, BufferedTransformation& bt);
void LoadBase64PrivateKey(const string& filename, PrivateKey& key);
void LoadBase64PublicKey(const string& filename, PublicKey& key);

void GenerationAndSaveRSAKeys(int keySize, const char* format, const char* privateKeyFile, const char* publicKeyFile) {
    string strFormat(format);
    string strPrivateKeyFile(privateKeyFile);
    string strPublicKeyFile(publicKeyFile);
    AutoSeededRandomPool rnd;

    // Generate private key
    RSA::PrivateKey rsaPrivate;
    rsaPrivate.GenerateRandomWithKeySize(rnd, keySize);

    // Generate public key
    RSA::PublicKey rsaPublic(rsaPrivate);

    if (strFormat == "DER") {
        // Save keys to file (BIN)
        SavePrivateKey(strPrivateKeyFile, rsaPrivate);
        SavePublicKey(strPublicKeyFile, rsaPublic);
    } else if (strFormat == "Base64") {
        // Save keys to file (BASE64)
        SaveBase64PrivateKey(strPrivateKeyFile, rsaPrivate);
        SaveBase64PublicKey(strPublicKeyFile, rsaPublic);
    } else {
        cerr << "Unsupported format. Please choose 'DER' or 'Base64'." << endl;
        exit(1);
    }

    Integer modul1 = rsaPrivate.GetModulus();
    Integer prime1 = rsaPrivate.GetPrime1();
    Integer prime2 = rsaPrivate.GetPrime2();
    Integer SK = rsaPrivate.GetPrivateExponent();

    Integer PK = rsaPublic.GetPublicExponent();
    Integer modul2 = rsaPublic.GetModulus();
    cout << "Modulo (private) n= " << modul1 << endl;
    cout << "Modulo (public) n= " << modul2 << endl;
    cout << "Prime number 1 (private) p= " << std::hex << prime1 << std::dec << endl;
    cout << "Prime number 2 (private) q= " << std::hex << prime2 << std::dec << endl;
    cout << "Secret exponent d= " << SK << endl;
    cout << "Public exponent e= " << PK << endl;

    // Checking the key generator function
    RSA::PrivateKey r1, r2;
    r1.GenerateRandomWithKeySize(rnd, 3072);

    SavePrivateKey("rsa-roundtrip.key", r1);
    LoadPrivateKey("rsa-roundtrip.key", r2);

    r1.Validate(rnd, 3);
    r2.Validate(rnd, 3);

    if (r1.GetModulus() != r2.GetModulus() ||
        r1.GetPublicExponent() != r2.GetPublicExponent() ||
        r1.GetPrivateExponent() != r2.GetPrivateExponent()) {
        throw runtime_error("key data did not round trip");
    }

    cout << "Successfully generated and saved RSA keys" << endl;
}


void RSAencrypt( const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CipherFile) {
    AutoSeededRandomPool rng;
    string strFormat(format);
    string strPublicKeyFile(publicKeyFile);        

    RSA::PublicKey publicKey;
    string plain, cipher, encoded;
    FileSource(PlaintextFile, true, new StringSink(plain), false);
    if (strFormat == "DER") {
        LoadPublicKey(strPublicKeyFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new FileSink(CipherFile, true)));
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    } else if (strFormat == "Base64") {
        LoadBase64PublicKey(strPublicKeyFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
        StringSource(cipher, true, new Base64Encoder(new StringSink(encoded)));
        StringSource(encoded, true, new FileSink(CipherFile, true));
    } else {
        cerr << "Unsupported format. Please choose 'DER' or 'Base64'." << endl;
        exit(1);
    }
	 // Xóa dấu xuống dòng khỏi encoded
    encoded.erase(remove(encoded.begin(), encoded.end(), '\n'), encoded.end());
    
}
string splitString(const string& input, int maxLength) {
    string result;
    int length = input.length();
    int currentPosition = 0;

    while (currentPosition < length) {
        // Lấy một phần của chuỗi có độ dài tối đa là maxLength
        string part = input.substr(currentPosition, maxLength);

        // Thêm ký tự xuống dòng vào cuối phần
        part += "\n";

        // Thêm phần vừa cắt vào chuỗi kết quả
        result += part;

        // Di chuyển vị trí hiện tại lên maxLength
        currentPosition += maxLength;
    }

    return result;
}
void RSAencryptFromScreen(string plain, const char* format, const char* publicKeyFile, const char* PlaintextFile, const char* CipherFile) {
    AutoSeededRandomPool rng;
    string strFormat(format);
    string strPublicKeyFile(publicKeyFile);        

    RSA::PublicKey publicKey;
    string cipher, encoded;


    if (strFormat == "DER") {
        LoadPublicKey(strPublicKeyFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new FileSink(CipherFile, true)));
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
    } else if (strFormat == "Base64") {
        LoadBase64PublicKey(strPublicKeyFile, publicKey);
        RSAES_OAEP_SHA_Encryptor e(publicKey);
        StringSource(plain, true, new PK_EncryptorFilter(rng, e, new StringSink(cipher)));
        StringSource(cipher, true, new Base64Encoder(new StringSink(encoded)));
        StringSource(encoded, true, new FileSink(CipherFile, true));
    } else {
        cerr << "Unsupported format. Please choose 'DER' or 'Base64'." << endl;
        exit(1);
    }
	 // Xóa dấu xuống dòng khỏi encoded
    encoded.erase(remove(encoded.begin(), encoded.end(), '\n'), encoded.end());
    
    cout << "Cipher text:\n" << encoded << endl;
}

void RSADecrypt(const char* format, const char* privateKeyFile, const char* CipherTextFile, const char* PlainTextFile) {
    string strFormat(format);
    RSA::PrivateKey privateKey;
    AutoSeededRandomPool rnd;
    string cipher, decoded;
    FileSource(CipherTextFile, true, new StringSink(cipher));
    decoded.clear();
    int b64 = 0;
    int lenCipher = cipher.size();
    for (int i = 0; i < lenCipher; i++) {
        if (cipher[i] > 'F')
            b64++;
    }
    if (strFormat == "DER") {
        LoadPrivateKey(privateKeyFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        string recover;
        StringSource(cipher, true, new PK_DecryptorFilter(rnd, d, new StringSink(recover)));
        StringSource(cipher, true, new PK_DecryptorFilter(rnd, d, new FileSink(PlainTextFile, true)));
    } else if (strFormat == "Base64" && b64 > 0) {
        StringSource(cipher, true, new Base64Decoder(new StringSink(decoded)));
        LoadBase64PrivateKey(privateKeyFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        string recover;
        StringSource(decoded, true, new PK_DecryptorFilter(rnd, d, new StringSink(recover)));
        StringSource(decoded, true, new PK_DecryptorFilter(rnd, d, new FileSink(PlainTextFile, true)));
    } else {
        cout << "Unsupported Format. Please choose 'DER' or 'Base64' " << endl;
        exit(1);
    }
}
void RSADecryptFromScreen(string cipher, const char* format, const char* privateKeyFile, const char* CipherTextFile, const char* PlainTextFile) {
    string strFormat(format);
    RSA::PrivateKey privateKey;
    AutoSeededRandomPool rnd;
    string decoded;
    decoded.clear();
    int b64 = 0;
    int lenCipher = cipher.size();
    for (int i = 0; i < lenCipher; i++) {
        if (cipher[i] > 'F')
            b64++;
    }
    if (strFormat == "DER") {
        LoadPrivateKey(privateKeyFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        string recover;
        StringSource(cipher, true, new PK_DecryptorFilter(rnd, d, new StringSink(recover)));
        StringSource(cipher, true, new PK_DecryptorFilter(rnd, d, new FileSink(PlainTextFile, true)));
    } else if (strFormat == "Base64" && b64 > 0) {
        StringSource(cipher, true, new Base64Decoder(new StringSink(decoded)));
        LoadBase64PrivateKey(privateKeyFile, privateKey);
        RSAES_OAEP_SHA_Decryptor d(privateKey);
        string recover;
        StringSource(decoded, true, new PK_DecryptorFilter(rnd, d, new StringSink(recover)));
        StringSource(decoded, true, new PK_DecryptorFilter(rnd, d, new FileSink(PlainTextFile, true)));
		cout << "PlainText :" << recover<<endl;
    } else {
        cout << "Unsupported Format. Please choose 'DER' or 'Base64' " << endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    // Set locale to support UTF-8
#ifdef _linux_
    std::locale::global(std::locale("C.utf8"));
#endif
#ifdef _WIN32
    // Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::ios_base::sync_with_stdio(false);
    if (argc < 2) {
        cerr << "Usage: \n"
             << argv[0] << " genkey <keysize> <format> <privateKeyFile> <publicKeyFile>\n"
             << argv[0] << " encrypt <format> <publicKeyFile> <plaintextFile> <cipherFile>\n"
             << argv[0] << " decrypt <format> <privateKeyFile> <cipherFile> <plaintextFile>\n";
        return -1;
    }

    string mode = argv[1];
    if (mode == "genkey" && argc == 6) {
        int keySize = std::stoi(argv[2]);
        GenerationAndSaveRSAKeys(keySize, argv[3], argv[4], argv[5]);
    } else if (mode == "encrypt" && argc == 6) {
        int select;
        cout << "Would you like to input text or file\n"
             << "1. Input Plain text\n"
             << "2. Input File\n";
        
        cin >> select;
        if (select == 2)
        {
        double averagetime = 0;
        for(int i =0 ;i<10000;i++)
        {
             auto start_time = std::chrono::high_resolution_clock::now();
             RSAencrypt(argv[2], argv[3], argv[4], argv[5]);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            averagetime += duration;
        }
        averagetime /= 10000.0;
        std::cout << "Average time for encryption over 10000 rounds: " << averagetime << " ms" << std::endl;
        }
        else if (select == 1)
        {
            string plain;
            cin.ignore();
            cout << "Enter the plain text: \n";
            getline(cin, plain);
            double averagetime = 0;
        for(int i =0 ;i<10000;i++)
        {
             auto start_time = std::chrono::high_resolution_clock::now();
             RSAencryptFromScreen(plain, argv[2], argv[3], argv[4], argv[5]);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            averagetime += duration;
        }
        averagetime /= 10000.0;
        std::cout << "Average time for encryption over 10000 rounds: " << averagetime << " ms" << std::endl;
        }
        
    } else if (mode == "decrypt" && argc == 6) {
        int select;
        cout << "Would you like to output to screen or file\n"
             << "1. Screen\n"
             << "2. File\n";
        
        cin >> select;
        if (select ==2)
        {
            double averagetime = 0;
        for(int i =0 ;i<10000;i++)
        {
            auto start_time = std::chrono::high_resolution_clock::now();
            RSADecrypt(argv[2], argv[3], argv[4], argv[5]);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            averagetime += duration;
        }
        averagetime /= 10000.0;
        std::cout << "Average time for encryption over 10000 rounds: " << averagetime << " ms" << std::endl;
        }
        else if (select == 1)
        {
            string cipher;
            cin.ignore();
            cout << "Enter the cipher text\n";
            getline(cin, cipher);
			cipher = splitString(cipher,88);
            double averagetime = 0;
        for(int i =0 ;i<10000;i++)
        {
            auto start_time = std::chrono::high_resolution_clock::now();
            RSADecryptFromScreen(cipher, argv[2], argv[3], argv[4], argv[5]);
            auto end_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
            averagetime += duration;
        }
        averagetime /= 10000.0;
        std::cout << "Average time for encryption over 10000 rounds: " << averagetime << " ms" << std::endl;
        }
        
        
    } else {
        cerr << "Invalid arguments. Please check the usage instructions.\n";
        return -1;
    }

    return 0;
}

// Save functions
void SavePrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);
    Save(filename, queue);
}

void SavePublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);
    Save(filename, queue);
}

void Save(const string& filename, const BufferedTransformation& bt) {
    FileSink file(filename.c_str());
    bt.CopyTo(file);
    file.MessageEnd();
}

void SaveBase64PrivateKey(const string& filename, const PrivateKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveBase64(filename, queue);
}

void SaveBase64PublicKey(const string& filename, const PublicKey& key) {
    ByteQueue queue;
    key.Save(queue);
    SaveBase64(filename, queue);
}

void SaveBase64(const string& filename, const BufferedTransformation& bt) {
    Base64Encoder encoder;
    bt.CopyTo(encoder);
    encoder.MessageEnd();
    Save(filename, encoder);
}

void LoadPrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;
    Load(filename, queue);
    key.Load(queue);
}

void LoadPublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;
    Load(filename, queue);
    key.Load(queue);
}

void Load(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true);
    file.TransferTo(bt);
    bt.MessageEnd();
}

void LoadBase64PrivateKey(const string& filename, PrivateKey& key) {
    ByteQueue queue;
    LoadBase64(filename, queue);
    key.Load(queue);
}

void LoadBase64PublicKey(const string& filename, PublicKey& key) {
    ByteQueue queue;
    LoadBase64(filename, queue);
    key.Load(queue);
}

void LoadBase64(const string& filename, BufferedTransformation& bt) {
    FileSource file(filename.c_str(), true, new Base64Decoder);
    file.TransferTo(bt);
    bt.MessageEnd();
}