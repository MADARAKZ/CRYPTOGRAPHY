// #include <cstdlib>
// #include <ctime>
#include <iostream>
#include <string>
#include<chrono>
#include <vector>
// #include <array>
// #include <stdexcept>
#include <map>
#include <stdint.h>
#include <iomanip>
#include <sstream>
/* Set utf8 support for windows*/ 
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#else
#endif
/* Convert string <--> utf8*/ 
#include <locale>
#include <codecvt>

using namespace std;
using  std::codecvt_utf8;
typedef vector<uint8_t> bytes;


bytes str_to_bytes(string s)
{
    vector<uint8_t> bytes(s.begin(), s.end());
    return bytes;
}

string bytes_to_str(bytes b)
{
    return string(b.begin(), b.end());
}
string hex(bytes &b)
{
    stringstream ss;
    ss << std::hex << std::setfill('0');
    
    for (const auto& byte : b) {
        ss << std::setw(2) << static_cast<int>(byte);
    }
    return ss.str();
}   

bytes decode_hex(string hexstr)
{
    vector<uint8_t> bytes_;
    for (size_t i = 0; i < hexstr.length(); i += 2) 
    {
        string byteString = hexstr.substr(i, 2);
        uint8_t b = static_cast<uint8_t>(stoul(byteString, nullptr, 16));
        bytes_.push_back(b);
    }
    return bytes_;
}

uint8_t gmul(uint8_t a, uint8_t b)
{
    int p = 0;
    for (int i = 0; i < 8; i++)
    {
        if (b & 1)
        {
            p ^= a;
        }
        int hi_bit_set = a & 0x80;
        a <<= 1;
        if (hi_bit_set)
        {
            a ^= 0x1b;
        }
        b >>= 1;
    }
    return p % 256;
}

bytes concat(bytes vector1, bytes vector2)
{
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());
    return vector1;
}
class AES
{
public:
    bytes key;
    int key_length;
    vector<bytes > round_keys;
    bytes S_BOX = 
    {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
    };
    bytes INV_S_BOX = {
        0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
        0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
        0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
        0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
        0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
        0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
        0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
        0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
        0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
        0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
        0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
        0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
        0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
        0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
        0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
    };
    vector<bytes > RCON = {
        {0x01, 0x00, 0x00, 0x00},
        {0x02, 0x00, 0x00, 0x00},
        {0x04, 0x00, 0x00, 0x00},
        {0x08, 0x00, 0x00, 0x00},
        {0x10, 0x00, 0x00, 0x00},
        {0x20, 0x00, 0x00, 0x00},
        {0x40, 0x00, 0x00, 0x00},
        {0x80, 0x00, 0x00, 0x00},
        {0x1B, 0x00, 0x00, 0x00}, 
        {0x36, 0x00, 0x00, 0x00}
    };
    AES(){}
    AES(bytes _key, int _key_length)
    {
        key = _key;
        key_length = _key_length;
        round_keys = key_expansion(key, key_length);
    }
    bytes sub_word(bytes word)
    {
        bytes sub;
        for(auto b : word)
        {
            sub.push_back(S_BOX[b]);
        }
        return sub;
    }
    bytes rot_word(bytes word)
    {
        bytes rot;
        for (int i = 1; i < word.size(); i++)
        {
            rot.push_back(word[i]);
        }
        rot.push_back(word[0]);
        return rot;
    }

    vector<bytes > key_expansion_128() 
    {
        int key_size = 16;
        int key_words = 4;
        vector<bytes > round_keys;
        for (int i = 0; i < key_size; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = key_words; i < 44; i++) 
        {  
            bytes temp = round_keys[i - 1];
            if (i % key_words == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - key_words) / key_words][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - key_words][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }

        return round_keys;  
    }
    vector<bytes > key_expansion_192() 
    {

        vector<bytes > round_keys;
        for (int i = 0; i < 24; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = 6; i < 52; i++) 
        {  
            vector <uint8_t> temp = round_keys[i - 1];
            if (i % 6 == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - 6) / 6][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - 6][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }
        return round_keys;  
    }
    
    vector<bytes > key_expansion_256() 
    {

        vector<bytes > round_keys;
        for (int i = 8; i < 32; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = 8; i < 60; i++) 
        {  
            vector <uint8_t> temp = round_keys[i - 1];
            if (i % 8 == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - 8) / 8][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - 8][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }
        return round_keys;  
    }
    
    vector<bytes > key_expansion(bytes _key, int length)
    {
        key = _key;
        if (length == 128)
            return key_expansion_128();
        if (length == 192)
            return key_expansion_192();
        if (length == 256)
            return key_expansion_256();
        else
            throw std::invalid_argument("Invalid key length. Supported lengths are 128, 192, and 256 bits.");
    }

    vector<bytes > sub_bytes(vector<bytes > state)
    {
        for(int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                int row = state[i][j] / 0x10;
                int col = state[i][j] % 0x10;
                state[i][j] = S_BOX[16 * row + col];
            }
        return state;
    }

    vector<bytes > shift_rows(vector<bytes > state)
    {
        // Second row: shift left by one byte
        state[1] = {state[1][1], state[1][2], state[1][3], state[1][0]};

        // Third row: shift left by two bytes
        state[2] = {state[2][2], state[2][3], state[2][0], state[2][1]};

        // Fourth row: shift left by three bytes
        state[3] = {state[3][3], state[3][0], state[3][1], state[3][2]};
        return state;
    }
    
    vector<bytes > mix_columns(vector<bytes > state)
    {
        for (int i = 0; i < 4; i++)
        {
            bytes col;
            for (int j = 0; j < 4; j++)
            {
                col.push_back(state[j][i]);
            }
            state[0][i] = gmul(0x02, col[0]) ^ gmul(0x03, col[1]) ^ col[2] ^ col[3];
            state[1][i] = col[0] ^ gmul(0x02, col[1]) ^ gmul(0x03, col[2]) ^ col[3];
            state[2][i] = col[0] ^ col[1] ^ gmul(0x02, col[2]) ^ gmul(0x03, col[3]);
            state[3][i] = gmul(0x03, col[0]) ^ col[1] ^ col[2] ^ gmul(0x02, col[3]);
        }

        return state;
    }

    vector<bytes > inv_mix_column(vector<bytes > state)
    {
        for (int i = 0; i < 4; i++)
        {
            bytes col;
            for (int j = 0; j < 4; j++)
            {
                col.push_back(state[j][i]);
            }
            state[0][i] = gmul(0x0E, col[0]) ^ gmul(0x0B, col[1]) ^ gmul(0x0D, col[2]) ^ gmul(0x09, col[3]);
            state[1][i] = gmul(0x09, col[0]) ^ gmul(0x0E, col[1]) ^ gmul(0x0B, col[2]) ^ gmul(0x0D, col[3]);
            state[2][i] = gmul(0x0D, col[0]) ^ gmul(0x09, col[1]) ^ gmul(0x0E, col[2]) ^ gmul(0x0B, col[3]);
            state[3][i] = gmul(0x0B, col[0]) ^ gmul(0x0D, col[1]) ^ gmul(0x09, col[2]) ^ gmul(0x0E, col[3]);

        }
        return state;
    }

    vector<bytes > add_round_key(vector<bytes > state, int round_number)
    {
        for(int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                state[j][i] ^= round_keys[round_number*4 + i][j];
            }
        }
        return state;
    }

    vector<bytes > inv_sub_bytes(vector<bytes > state)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int row = state[i][j] / 0x10;
                int col = state[i][j] % 0x10;
                state[i][j] = INV_S_BOX[16 * row + col];
            }
        }
        return state;
    }

    vector<bytes > inv_shift_rows(vector<bytes > state)
    {
        state[1] = {state[1][3], state[1][0], state[1][1], state[1][2]};
        state[2] = {state[2][2], state[2][3], state[2][0], state[2][1]};
        state[3] = {state[3][1], state[3][2], state[3][3], state[3][0]};
        return state;
    }

    bytes encrypt(bytes data)
    {

        if (round_keys.empty())
        {
            round_keys = key_expansion(key, key.size());
        }
        // Convert data into state matrix
        vector<bytes > state;
        for (int i = 0; i < data.size(); i += 4) 
        {
            bytes column;
            for (int j = 0; j < 4; j++)
            {
                column.push_back(data[i + j]);
            }
            state.push_back(column);
        }
        // Number of rounds depends on the key length: 10 for 128, 12 for 192, and 14 for 256
        map<int, int> mp;
        mp[16] = 10;
        mp[24] = 12;
        mp[32] = 14;
        int num_rounds = mp[key.size()];

        // Initial round
        state = add_round_key(state, 0);
        
        // Main rounds
        for (int round = 1; round < num_rounds; round++) 
        {
            state = sub_bytes(state);
            state = shift_rows(state);
            state = mix_columns(state);
            state = add_round_key(state, round);
        }

        // Final round
        state = sub_bytes(state);
        state = shift_rows(state);
        state = add_round_key(state, num_rounds);

        // Convert state matrix back to bytes
        bytes result;
        for (const bytes& column : state) 
        {
            for (const uint8_t& byte : column) {
                result.push_back(byte);
            }
        }
        return result;
    }

    bytes decrypt(bytes ciphertext)
    {
        if (round_keys.empty()) 
        {
            round_keys = key_expansion(key, key.size());
        }
        vector<bytes > state;
        for (size_t i = 0; i < ciphertext.size(); i += 4) 
        {
            bytes column;
            for (int j = 0; j < 4; j++)
            {
                column.push_back(ciphertext[i + j]);
            }
            state.push_back(column);
        }
        
        map<int, int> mp;
        mp[16] = 10;
        mp[24] = 12;
        mp[32] = 14;
        int num_rounds = mp[key.size()];
        state = add_round_key(state, num_rounds);
        
        for (int round = num_rounds - 1; round > 0; round-- )
        {
            state = inv_shift_rows(state);
            state = inv_sub_bytes(state);
            state = add_round_key(state, round);
            state = inv_mix_column(state);
        }
        state = inv_shift_rows(state);
        state = inv_sub_bytes(state);
        state = add_round_key(state, 0);
        bytes result;
        for (auto column : state) 
        {
            for (auto byte : column) 
            {
                result.push_back(byte);
            }
        }
        return result;
    }
    
};
class modes
{
public:
    bytes iv;
    int key_length;
    AES aes;
    
    modes(bytes key, bytes iv)
    {
        key_length = key.size() * 8;
        if (key_length != 128 && key_length != 192 && key_length != 256)
        {
            throw invalid_argument("Invalid key length. Supported lengths are 128, 192, and 256 bits.");
        }
        aes = AES(key, key_length);
        this->iv = iv; // Sử dụng IV được truyền vào từ hàm main
    }
    
    bytes pkcs7_padding(bytes data)
    {
        int padding_length = 16 - (data.size() % 16);
        bytes padding_data(padding_length, padding_length);
        data.insert(data.end(), padding_data.begin(), padding_data.end());   
        return data;
    }

    bytes pkcs7_unpadding(bytes data)
    {
        int padding_length = data[data.size() - 1];
        bytes unpadded_data;
        for (int i = 0; i < data.size() - padding_length; i++)
        {
            unpadded_data.push_back(data[i]);
        }
        return unpadded_data;
    }

    bytes cbc_encrypt(bytes plaintext)
    {

        bytes padded_data = pkcs7_padding(plaintext);
            
        vector<bytes > encrypted_blocks;
        bytes previous_block = iv;
        for (int i = 0; i < padded_data.size(); i += 16)
        {
            bytes block;
            for (int j = i; j < 16 + i; j++)
            {
                block.push_back(padded_data[j]);
            }
            for (int j = 0; j < 16; j++)
                block[j] = block[j] ^ previous_block[j];

            bytes encrypted_block = aes.encrypt(block);
            encrypted_blocks.push_back(encrypted_block);
            previous_block = encrypted_block;
        }
        bytes res = iv;
        for (auto block : encrypted_blocks)
        {
            res = concat(res, block);
        }
        return res;
    }

    bytes cbc_decrypt(bytes ciphertext)
    {
        if (ciphertext.size() % 16 != 0)
            throw invalid_argument("Ciphertext length must be a multiple of 16 bytes for CBC mode.");
        bytes iv_, cipher;
        for (int i = 0; i < ciphertext.size(); i++)
        {
            if (i < 16)
                iv_.push_back(ciphertext[i]);
            else
                cipher.push_back(ciphertext[i]);
        }
        ciphertext = cipher;
        vector<bytes > decrypted_blocks;
        bytes previous_block = iv;
        for (int i = 0; i < ciphertext.size(); i += 16)
        {
            bytes block;
            for (int j = i; j < i + 16; j++ )
            {
                block.push_back(ciphertext[j]);
            }
            bytes decrypted_block = aes.decrypt(block);

            for (int j = 0; j < 16; j++)
            {
                decrypted_block[j] = decrypted_block[j] ^ previous_block[j];
            }
            decrypted_blocks.push_back(decrypted_block);
            previous_block = block;
        }
        bytes decrypted_data = decrypted_blocks[0];
        for (int i = 1; i < decrypted_blocks.size(); i++)
        {
            decrypted_data = concat(decrypted_data, decrypted_blocks[i]);
        }
        return pkcs7_unpadding(decrypted_data);
    }

};
class key_expansion
{
private:
    bytes key;
    bytes S_BOX = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
    };
    vector<bytes > RCON = {
        {0x01, 0x00, 0x00, 0x00},
        {0x02, 0x00, 0x00, 0x00},
        {0x04, 0x00, 0x00, 0x00},
        {0x08, 0x00, 0x00, 0x00},
        {0x10, 0x00, 0x00, 0x00},
        {0x20, 0x00, 0x00, 0x00},
        {0x40, 0x00, 0x00, 0x00},
        {0x80, 0x00, 0x00, 0x00},
        {0x1B, 0x00, 0x00, 0x00}, 
        {0x36, 0x00, 0x00, 0x00}
    };
public:
    key_expansion(bytes _key)
    {
        key = _key;
    }
    bytes sub_word(bytes word)
    {
        bytes sub;
        for(auto b : word)
        {
            if (0 <= b)
            {
                sub.push_back(b);
            }
        }
        return sub;
    }

    bytes rot_word(bytes word)
    {
        bytes rot;
        for (int i = 1; i < word.size(); i++)
        {
            rot.push_back(word[i]);
        }
        rot.push_back(word[0]);
        return rot;
    }

    vector<bytes > key_expansion_128() 
    {
        int key_size = 16;
        int key_words = 4;
        vector<bytes > round_keys;
        for (int i = 0; i < key_size; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = key_words; i < 44; i++) 
        {  
            bytes temp = round_keys[i - 1];
            if (i % key_words == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - key_words) / key_words][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - key_words][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }

        return round_keys;  
    }
    vector<bytes > key_expansion_192() 
    {

        vector<bytes > round_keys;
        for (int i = 0; i < 24; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = 6; i < 52; i++) 
        {  
            bytes temp = round_keys[i - 1];
            if (i % 6 == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - 6) / 6][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - 6][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }
        return round_keys;  
    }
    
    vector<bytes > key_expansion_256() 
    {

        vector<bytes > round_keys;
        for (int i = 8; i < 32; i += 4) 
        {
            bytes key_word(4);
            for (int j = 0; j < 4; j++) 
            {
                key_word[j] = key[i + j];
            }
            round_keys.push_back(key_word);
        }
        for (int i = 8; i < 60; i++) 
        {  
            bytes temp = round_keys[i - 1];
            if (i % 8 == 0) 
            {
                temp = sub_word(rot_word(temp));
                for (int j = 0; j < 4; j++) 
                {
                    temp[j] ^= RCON[(i - 8) / 8][j];  
                }
            }
            bytes new_key_word(4);
            for (int j = 0; j < 4; j++) {
                new_key_word[j] = round_keys[i - 8][j] ^ temp[j];
            }
            round_keys.push_back(new_key_word);
        }
        return round_keys;  
    }
    

};
int main(int argc, char* argv[])
{
    #ifdef __linux__
    std::locale::global(std::locale("C.UTF-8"));
    #endif
  
    #ifdef _WIN32
    // Set console code page to UTF-8 on Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    string key;
    string IV;
    
    cout << "Please enter your key: ";
    cin >> key;
    cout << "Please enter your IV (16 bytes): ";
    cin >> IV;
    
    bytes key_bytes = str_to_bytes(key);
    bytes IV_bytes = str_to_bytes(IV); // Chuyển IV thành dạng bytes
    modes aes_cbc = modes(key_bytes, IV_bytes); // Truyền IV dưới dạng bytes
    
    while (true)
    {
        int aes;
        cout << "1. Encrypt\n"
        << "2. Decrypt\n"
        << "Please enter a number(1-2): ";
        cin >> aes;
        
        if (aes == 1)
        {
            string plain;
            cout << "Enter plaintext:";
            cin.ignore();
            getline(cin, plain); 
            bytes plain_bytes = str_to_bytes(plain);
             bytes cipher ;
            auto start_encrypt = std::chrono::steady_clock::now();
        for (int i = 0; i < 10000; ++i) {
         cipher = aes_cbc.cbc_encrypt(plain_bytes);
        }
           auto end_encrypt = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds_encrypt = end_encrypt - start_encrypt;
            double total_encrypt_time = elapsed_seconds_encrypt.count();
            cout << "Encrypted data(hex): " << hex(cipher) << endl;
            std::cout << "Total encryption time for 10,000 iterations: " << total_encrypt_time/10000 << "s\n";
        }
        else if (aes == 2)
        {
            string cipherHex;
            cout << "Enter ciphertext(hex): ";
            cin >> cipherHex;
               bytes recovered;
            auto start_encrypt = std::chrono::steady_clock::now();
        for (int i = 0; i < 10000; ++i) {
         recovered = aes_cbc.cbc_decrypt(decode_hex(cipherHex));
        }
           auto end_encrypt = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds_encrypt = end_encrypt - start_encrypt;
            double total_decrypt_time = elapsed_seconds_encrypt.count();
            cout << "Decrypted data: " << bytes_to_str(recovered);
             std::cout << "Total decryption time for 10,000 iterations: " << total_decrypt_time/10000 << "s\n";
            return 0;
        }
        else 
        {
            cout << "Invalid options";
            return 0;
        }
    }
    return 0;
}
