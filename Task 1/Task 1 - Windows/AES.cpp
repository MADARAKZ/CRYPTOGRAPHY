// C/C++ Standard Libraries
#include <sstream>
#include <assert.h>
#include <streambuf>
#include <iostream>
#include <fstream>
#include <stdio.h>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include <chrono>
#include <string>
using std::string;

#include <exception>
using std::exception;

#include "cryptopp/base64.h"
using CryptoPP::Base64Decoder;
using CryptoPP::Base64Encoder;
#include "cryptopp/hex.h"
using CryptoPP::HexDecoder;
using CryptoPP::HexEncoder;

#include "cryptopp/cryptlib.h"
using CryptoPP::AuthenticatedSymmetricCipher;
using CryptoPP::BufferedTransformation;
using CryptoPP::DecodingResult;
using CryptoPP::Exception;
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;

#include "cryptopp/files.h"
using CryptoPP::FileSink;
using CryptoPP::FileSource;

#include "cryptopp/filters.h"
using CryptoPP::ArraySink;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::HashVerificationFilter;
using CryptoPP::PK_DecryptorFilter;
using CryptoPP::PK_EncryptorFilter;
using CryptoPP::Redirector;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::StringSink;
using CryptoPP::StringSource;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

#include "cryptopp/queue.h"
using CryptoPP::ByteQueue;

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

// DES Libary
#include "cryptopp/aes.h"
using CryptoPP::AES;

// Confidentiality only modes
#include "cryptopp/modes.h"
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::CTR_Mode;
using CryptoPP::ECB_Mode;
using CryptoPP::OFB_Mode;

// Confidentiality and Authentication modes
#include "cryptopp/ccm.h"
using CryptoPP::CCM;

#include "cryptopp/eax.h"
using CryptoPP::EAX;

#include "cryptopp/gcm.h"
using CryptoPP::GCM;

#include "cryptopp/xts.h"
using CryptoPP::XTS;
#include "cryptopp/ccm.h"
using CryptoPP::CCM;
#include "cryptopp/gcm.h"
using CryptoPP::GCM;

// Define platform-specific features
#ifdef _WIN32
#include <Windows.h>
#endif
void SaveKey(const string &filename, const SecByteBlock &bt);
void SaveIV(const string &filename, const SecByteBlock &bt);
void SaveKeyBase64(const string &filename, const SecByteBlock &bt);
void SaveIVBase64(const string &filename, const SecByteBlock &bt);
void SaveKeyHex(const string &filename, const SecByteBlock &bt);
void SaveIVHex(const string &filename, const SecByteBlock &bt);
void LoadKey(const string &filename, SecByteBlock &bt);
void LoadIV(const string &filename, SecByteBlock &bt);
void LoadKeyBase64(const string &filename, SecByteBlock &bt);
void LoadIVBase64(const string &filename, SecByteBlock &bt);
void LoadKeyHex(const string &filename, SecByteBlock &bt);
void LoadIVHex(const string &filename, SecByteBlock &bt);
string ConvertToPEM(const string &cipher);
string ConvertToHex(const string &cipher);
string ConvertFromPEM(const string &pemCipher);
string ConvertFromHex(const string &hexCipher);
string stringconvert(const char *mode);
size_t GetKeySizeFromFile(const string &filename, const string &format);
void GenerateAndSaveIV_Keys(const int KeySize, const char *KeyFormat, const char *KeyFileName);
void LoadKeyFromFile(const string &KeyFile, SecByteBlock &key, const string &strKeyFormat);
void LoadIVFromFile(SecByteBlock &iv, const string &strKeyFormat);
void LoadKeyIVFromFile(const string &KeyFile, SecByteBlock &key, SecByteBlock &iv, const string &strMode, const string &strKeyFormat);
string LoadCipherText(const char *CipherFile, const string &strCipherFormat);
string LoadPlainText(const char *PlaintextFile, const string &strPlaintextFormat);
void SaveCipherFile(const string &cipher, const string &strCipherFormat, const char *CipherFile);
void SaveRecoveredFile(const string &recovered, const string &strPlaintextFormat, const char *RecoveredFile);
void RunMain(const string &action, int argc, char *argv[]);

// Encryption Modes
void EncryptECB(const SecByteBlock &key, const string &plain, string &cipher);
void EncryptCBC(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptCFB(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptOFB(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptCTR(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptGCM(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptCCM(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);
void EncryptXTS(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher);

// Decryption Modes
void DecryptECB(const SecByteBlock &key, const string &cipher, string &recovered);
void DecryptCBC(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptCFB(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptOFB(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptCTR(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptGCM(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptCCM(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);
void DecryptXTS(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered);

// Helper Functions
void Encryption(const char *mode, const char *KeyFile, const char *KeyFormat, const char *PlaintextFile, const char *PlaintextFormat, const char *CipherFile, const char *CipherFormat);
void Decryption(const char *mode, const char *KeyFile, const char *KeyFormat, const char *RecoveredFile, const char *RecoveredFormat, const char *CipherFile, const char *CipherFormat);

// Encryption mode functions
void EncryptECB(const SecByteBlock &key, const string &plain, string &cipher)
{
    ECB_Mode<AES>::Encryption e;
    e.SetKey(key, key.size());

    StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));
}

void EncryptCBC(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
        CBC_Mode<AES>::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));

}

void EncryptCFB(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    CFB_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));
}

void EncryptOFB(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    OFB_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));
}

void EncryptCTR(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    CTR_Mode<AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));
}

void EncryptGCM(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    const int TAG_SIZE = 12;
    GCM<AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss1(plain, true, new AuthenticatedEncryptionFilter(e, new StringSink(cipher), false, TAG_SIZE));
}

void EncryptCCM(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    const int TAG_SIZE = 8;
    CCM<AES, TAG_SIZE>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);
    e.SpecifyDataLengths(0, plain.size(), 0);

    StringSource ss(plain, true, new AuthenticatedEncryptionFilter(e, new StringSink(cipher)));
}

void EncryptXTS(const SecByteBlock &key, const SecByteBlock &iv, const string &plain, string &cipher)
{
    XTS<AES>::Encryption e;
    e.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(plain, true, new StreamTransformationFilter(e, new StringSink(cipher)));
}

// Decryption mode functions
void DecryptECB(const SecByteBlock &key, const string &cipher, string &recovered)
{
    ECB_Mode<AES>::Decryption d;
    d.SetKey(key, key.size());

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void DecryptCBC(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    CBC_Mode<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void DecryptCFB(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    CFB_Mode<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void DecryptOFB(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    OFB_Mode<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void DecryptCTR(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    CTR_Mode<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void DecryptGCM(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    GCM<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new AuthenticatedDecryptionFilter(d, new StringSink(recovered), AuthenticatedDecryptionFilter::THROW_EXCEPTION));
}

void DecryptCCM(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    const int TAG_SIZE = 8;
    CCM<AES, TAG_SIZE>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);
    d.SpecifyDataLengths(0, cipher.size() - TAG_SIZE, 0);

    StringSource ss(cipher, true, new AuthenticatedDecryptionFilter(d, new StringSink(recovered), AuthenticatedDecryptionFilter::THROW_EXCEPTION));
}

void DecryptXTS(const SecByteBlock &key, const SecByteBlock &iv, const string &cipher, string &recovered)
{
    XTS<AES>::Decryption d;
    d.SetKeyWithIV(key, key.size(), iv);

    StringSource ss(cipher, true, new StreamTransformationFilter(d, new StringSink(recovered)));
}

void GenerateAndSaveIV_Keys(const int KeySize, const char *KeyFormat, const char *KeyFileName)
{
    AutoSeededRandomPool prng;

    SecByteBlock key(KeySize);
    SecByteBlock iv(AES::BLOCKSIZE);
    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    string strKeyFormat = stringconvert(KeyFormat);

    if (strKeyFormat == "DER")
    {
        SaveKey(KeyFileName, key);
        SaveIV(KeyFileName, iv);
    }
    else if (strKeyFormat == "PEM")
    {
        SaveKeyBase64(KeyFileName, key);
        SaveIVBase64(KeyFileName, iv);
    }
    else if (strKeyFormat == "HEX")
    {
        SaveKeyHex(KeyFileName, key);
        SaveIVHex(KeyFileName, iv);
    }
}

void LoadKeyFromFile(const string &KeyFile, SecByteBlock &key, const string &strKeyFormat)
{
    if (strKeyFormat == "DER")
        LoadKey(KeyFile, key);
    else if (strKeyFormat == "PEM")
        LoadKeyBase64(KeyFile, key);
    else if (strKeyFormat == "HEX")
        LoadKeyHex(KeyFile, key);
}

void LoadIVFromFile(const string &KeyFile, SecByteBlock &iv, const string &strKeyFormat)
{
    if (strKeyFormat == "DER")
        LoadIV(KeyFile, iv);
    else if (strKeyFormat == "PEM")
        LoadIVBase64(KeyFile, iv);
    else if (strKeyFormat == "HEX")
        LoadIVHex(KeyFile, iv);
}

void LoadKeyIVFromFile(const string &KeyFile, SecByteBlock &key, SecByteBlock &iv, const string &strMode, const string &strKeyFormat)
{
    LoadKeyFromFile(KeyFile, key, strKeyFormat);

    if (strMode != "ECB")
    {
        LoadIVFromFile(KeyFile, iv, strKeyFormat);
    }
}
string LoadPlainText(const char *PlaintextFile, const string &strPlaintextFormat)
{
    string plain;
    


    std::ifstream inputFile(PlaintextFile);
    if (!inputFile.is_open())
    {
        throw runtime_error("Error opening input file.");
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    plain = buffer.str();
    inputFile.close();

    return plain;
}

string LoadCipherText(const char *CipherFile, const string &strCipherFormat)
{
    string cipher;
    
    if (strCipherFormat == "Text")
    {
        std::ifstream inputFile(CipherFile);
        if (!inputFile.is_open())
        {
            throw runtime_error("Error opening input file.");
        }

        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        cipher = buffer.str();
        inputFile.close();
    }
    else if (strCipherFormat == "PEM")
    {
        cipher = ConvertFromPEM(LoadPlainText(CipherFile, strCipherFormat));
    }
    else if (strCipherFormat == "HEX")
    {
        cipher = ConvertFromHex(LoadPlainText(CipherFile, strCipherFormat));
    }
    else
    {
        throw runtime_error("Unsupported cipher format.");
    }

    return cipher;
}

void SaveCipherFile(const string &cipher, const string &strCipherFormat, const char *CipherFile)
{
    std::ofstream outputFile(CipherFile);
    
    if (!outputFile.is_open())
    {
        throw runtime_error("Error opening output file.");
    }

    try
    {
        if (strCipherFormat == "Text")
        {
            outputFile << cipher;
        }
        else if (strCipherFormat == "PEM")
        {
            string pemCipher = ConvertToPEM(cipher);
            outputFile << pemCipher;
        }
        else if (strCipherFormat == "HEX")
        {
            string hexCipher = ConvertToHex(cipher);
            outputFile << hexCipher;
        }
        else
        {
            throw runtime_error("Unsupported cipher format.");
        }
    }
    catch (const exception& ex)
    {
        // Close the file if an exception occurs before closing
        outputFile.close();
        throw runtime_error(string("Error writing to output file: ") + ex.what());
    }

    outputFile.close(); // Always close the file after writing
}


void SaveRecoveredFile(const string &recovered, const string &strPlaintextFormat, const char *RecoveredFile)
{

    std::ofstream outputFile(RecoveredFile);
    if (!outputFile.is_open())
    {
        throw runtime_error("Error opening output file.");
    }

    try
    {
        outputFile << recovered;
    }
    catch (const std::exception& ex)
    {
        // Close the file if an exception occurs before closing
        outputFile.close();
        throw runtime_error(string("Error writing to output file: ") + ex.what());
    }

    outputFile.close(); // Always close the file after writing
}


void Encryption(const char *mode, const char *KeyFile, const char *KeyFormat, const char *PlainFile, const char *PlainFormat, const char *CipherFile, const char *CipherFormat)
{
    string strMode = stringconvert(mode);
    string strKeyFormat = stringconvert(KeyFormat);
    string strPlainFormat = stringconvert(PlainFormat);
    string strCipherFormat = stringconvert(CipherFormat);

    SecByteBlock key;
    SecByteBlock iv(AES::BLOCKSIZE);

    LoadKeyIVFromFile(KeyFile, key, iv, strMode, strKeyFormat);

    string plain = LoadPlainText(PlainFile, strPlainFormat);
     if (plain.empty())
    {
        throw runtime_error("Failed to load plain text.");
    }

    string cipher;

    if (strMode == "ECB")
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    cipher = "";
            EncryptECB(key, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for ECB encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CBC")
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    cipher = "";
            EncryptCBC(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CBC encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CFB")
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    cipher = "";
            EncryptCFB(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CFB encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "OFB")
    {   
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    cipher = "";
            EncryptOFB(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for OFB encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CTR")
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {   cipher = "";
            EncryptCTR(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CTR encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "GCM")
    {    cipher = "";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {
            cipher = "";
            EncryptGCM(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for GCM encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CCM")
    {    cipher = "";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    cipher = "";
            EncryptCCM(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CCM encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "XTS")
    {    cipher = "";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {   cipher = "";
            EncryptXTS(key, iv, plain, cipher);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for XTS encryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }

    SaveCipherFile(cipher, strCipherFormat, CipherFile);
}
void Decryption(const char *mode, const char *KeyFile, const char *KeyFormat, const char *CipherFile, const char *CipherFormat, const char *PlainFile, const char *PlainFormat)
{
    string strMode = stringconvert(mode);
    SecByteBlock key;
    SecByteBlock iv(AES::BLOCKSIZE);
    LoadKeyIVFromFile(KeyFile, key, iv, mode, KeyFormat);

    string cipher = LoadCipherText(CipherFile, CipherFormat);
   if (cipher.empty())
   {
    cout << "cipher no load";
   }
    string plain;
    if (strMode == "ECB")
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {   plain = "";
            DecryptECB(key, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for ECB decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CBC")
    {  
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {     plain = "";
            DecryptCBC(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CBC decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CFB")
    { 
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {     plain = "";
            DecryptCFB(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CFB decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "OFB")
    {     plain = "";
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    plain = "";
            DecryptOFB(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for OFB decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CTR")
    {    
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    plain = "";
            DecryptCTR(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CTR decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "GCM")
    {  
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    plain = "";
            DecryptGCM(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for GCM decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "CCM")
    {    
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {    plain = "";
            DecryptCCM(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for CCM decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }
    else if (strMode == "XTS")
    {    
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 10000; ++i)
        {
             plain = "";
            DecryptXTS(key, iv, cipher, plain);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for XTS decryption: " << duration.count() / 10000.0 << " milliseconds\n";
    }

      SaveRecoveredFile(plain, PlainFormat, PlainFile);
}
void RunMain(const string &action, int argc, char *argv[])
{
    cout<<action;
    if (action == "GENKEY")
    {
        int KeySize = atoi(argv[2]);
        const char *KeyFormat = argv[3];
        const char *KeyFileName = argv[4];

        GenerateAndSaveIV_Keys(KeySize /8, KeyFormat, KeyFileName);
    }
    else if (action == "ENCRYPT")
    {
        const char *mode = argv[2];
        const char *KeyFile = argv[3];
        const char *KeyFormat = argv[4];
        const char *PlaintextFile = argv[5];
        const char *PlaintextFormat = argv[6];
        const char *CipherFile = argv[7];
        const char *CipherFormat = argv[8];

        Encryption(mode, KeyFile, KeyFormat, PlaintextFile, PlaintextFormat, CipherFile, CipherFormat);
    }
    else if (action == "DECRYPT")
    {
        const char *mode = argv[2];
        const char *KeyFile = argv[3];
        const char *KeyFormat = argv[4];
        const char *RecoveredFile = argv[5];
        const char *RecoveredFormat = argv[6];
        const char *CipherFile = argv[7];
        const char *CipherFormat = argv[8];

        Decryption(mode, KeyFile, KeyFormat, RecoveredFile, RecoveredFormat, CipherFile, CipherFormat);
    }
    else
    {
        cerr << "Unknown action: " << action << endl;
    }
}

int main(int argc, char *argv[])
{
    #ifdef _linux_
    std::locale::global(std::locale("C.utf8"));
#endif
#ifdef _WIN32
    // Set console code page to UTF-8 on Windows C.utf8, CP_UTF8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    std::ios_base::sync_with_stdio(false);
    if (argc < 2)
    {
         std::cerr << "Error: Insufficient arguments provided.\n\n";
    std::cerr << "Instructions:\n";
    std::cerr << "\tTo generate a key:\n";
    std::cerr << "\t\t" << argv[0] << " genkey <KeySize> <KeyFileFormat> <KeyFile>\n";
    std::cerr << "\tTo encrypt a file:\n";
    std::cerr << "\t\t" << argv[0] << " encrypt CTR key.pem PEM plain.txt Text cipher.bin HEX\n";
    std::cerr << "\tTo decrypt a file:\n";
    std::cerr << "\t\t" << argv[0] << " decrypt CTR key.pem PEM recovered.txt Text cipher.bin HEX\n\n";

    std::cerr << "Parameters:\n";
    std::cerr << "\t<KeySize>: Size of the key in bits. Options: 128, 192, 256, 512 (only XTS)\n";
    std::cerr << "\t<Mode>: Encryption mode. Options: 'ECB', 'CBC', 'CFB', 'OFB', 'CTR', 'GCM', 'CCM', 'XTS (>=256)'\n";
    std::cerr << "\t<KeyFileFormat> and <CipherFormat>: Options: 'DER', 'PEM', 'HEX'\n";
    std::cerr << "\t<PlaintextFormat> and <RecoveredFileFormat>: Options: 'Text', 'DER', 'PEM', 'HEX'\n\n";

    std::cerr << "Example:\n";
    std::cerr << "\tGenerate a key:\n";
    std::cerr << "\t\t" << argv[0] << " genkey 256 PEM key.pem\n";
    std::cerr << "\tEncrypt a file using Counter (CTR) mode:\n";
    std::cerr << "\t\t" << argv[0] << " encrypt CTR key.pem PEM plain.txt Text cipher.bin HEX\n";
    std::cerr << "\tDecrypt a file using Counter (CTR) mode:\n";
    std::cerr << "\t\t" << argv[0] << " decrypt CTR key.pem PEM recovered.txt Text cipher.bin HEX\n";

    return -1;
    }

    string action = argv[1];
    transform(action.begin(), action.end(), action.begin(), ::toupper);

    try
    {
        RunMain(action, argc, argv);
    }
    catch (const Exception &e)
    {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const runtime_error &e)
    {
        cerr << "Runtime error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

// Define the helper functions for saving and loading keys and IVs
void SaveKey(const string &filename, const SecByteBlock &bt)
{
    FileSink file(filename.c_str());
    file.Put(bt, bt.size());
}

void SaveIV(const string &filename, const SecByteBlock &bt)
{
    FileSink file((filename + ".iv").c_str());
    file.Put(bt, bt.size());
}

void SaveKeyBase64(const string &filename, const SecByteBlock &bt)
{
    Base64Encoder encoder(new FileSink(filename.c_str()));
    encoder.Put(bt, bt.size());
    encoder.MessageEnd();
}

void SaveIVBase64(const string &filename, const SecByteBlock &bt)
{
    Base64Encoder encoder(new FileSink((filename + ".iv").c_str()));
    encoder.Put(bt, bt.size());
    encoder.MessageEnd();
}

void SaveKeyHex(const string &filename, const SecByteBlock &bt)
{
    HexEncoder encoder(new FileSink(filename.c_str()));
    encoder.Put(bt, bt.size());
    encoder.MessageEnd();
}

void SaveIVHex(const string &filename, const SecByteBlock &bt)
{
    HexEncoder encoder(new FileSink((filename + ".iv").c_str()));
    encoder.Put(bt, bt.size());
    encoder.MessageEnd();
}

void LoadKey(const string &filename, SecByteBlock &bt)
{
    FileSource file(filename.c_str(), true);
    bt.resize(file.MaxRetrievable());
    file.Get(bt, bt.size());
}

void LoadIV(const string &filename, SecByteBlock &bt)
{
    FileSource file((filename + ".iv").c_str(), true);
    bt.resize(file.MaxRetrievable());
    file.Get(bt, bt.size());
}

void LoadKeyBase64(const string &filename, SecByteBlock &bt)
{
    Base64Decoder decoder;
    FileSource file(filename.c_str(), true, new Redirector(decoder));
    bt.resize(decoder.MaxRetrievable());
    decoder.Get(bt, bt.size());
}

void LoadIVBase64(const string &filename, SecByteBlock &bt)
{
    Base64Decoder decoder;
    FileSource file((filename + ".iv").c_str(), true, new Redirector(decoder));
    bt.resize(decoder.MaxRetrievable());
    decoder.Get(bt, bt.size());
}

void LoadKeyHex(const string &filename, SecByteBlock &bt)
{
    HexDecoder decoder;
    FileSource file(filename.c_str(), true, new Redirector(decoder));
    bt.resize(decoder.MaxRetrievable());
    decoder.Get(bt, bt.size());
}

void LoadIVHex(const string &filename, SecByteBlock &bt)
{
    HexDecoder decoder;
    FileSource file((filename + ".iv").c_str(), true, new Redirector(decoder));
    bt.resize(decoder.MaxRetrievable());
    decoder.Get(bt, bt.size());
}

string ConvertToPEM(const string &cipher)
{
    string encoded;
    StringSource ss(cipher, true, new Base64Encoder(new StringSink(encoded), false));
    return encoded;
}

string ConvertToHex(const string &cipher)
{
    string encoded;
    StringSource ss(cipher, true, new HexEncoder(new StringSink(encoded), false));
    return encoded;
}

string ConvertFromPEM(const string &pemCipher)
{
    string decoded;
    StringSource ss(pemCipher, true, new Base64Decoder(new StringSink(decoded)));
    return decoded;
}

string ConvertFromHex(const string &hexCipher)
{
    string decoded;
    StringSource ss(hexCipher, true, new HexDecoder(new StringSink(decoded)));
    return decoded;
}

string stringconvert(const char *mode)
{
    string strMode(mode);
    transform(strMode.begin(), strMode.end(), strMode.begin(), ::toupper);
    return strMode;
}