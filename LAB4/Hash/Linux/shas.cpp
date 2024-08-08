#include <openssl/evp.h>
#include <iostream>
#include <fstream>
#include <cstring> // For strerror and strlen
#include <iomanip> // For setw and setfill
#include <chrono>
#include <errno.h>

using namespace std;

void hashes(const char* algo, const char* input_data, const char* output_filename, int input_choice, int output_choice)
{
    EVP_MD_CTX *hashes;
    const EVP_MD *md = EVP_get_digestbyname(algo);

    if (!md) {
        cerr << "Unknown message digest " << algo << endl;
        exit(EXIT_FAILURE);
    }

    ofstream f_out;
    if (output_choice == 2) {
        f_out.open(output_filename);
        if (!f_out.is_open()) {
            perror("Failed to open output file");
            exit(EXIT_FAILURE);
        }
    }

    // Setting up the hashing context
    hashes = EVP_MD_CTX_new();
    EVP_DigestInit_ex(hashes, md, NULL);

    if (input_choice == 1) {
        // Directly hash the input_data provided by the user
        EVP_DigestUpdate(hashes, input_data, strlen(input_data));
    } else if (input_choice == 2) {
        // Read from the file and update the digest
        FILE *f_in = fopen(input_data, "rb");
        if (!f_in) {
            perror("Failed to open input file");
            if (f_out.is_open()) f_out.close();
            exit(EXIT_FAILURE);
        }

        unsigned char buffer[4096];
        size_t read_bytes;
        while ((read_bytes = fread(buffer, 1, sizeof(buffer), f_in)) != 0) {
            EVP_DigestUpdate(hashes, buffer, read_bytes);
        }
        fclose(f_in);
    }

    unsigned char md_value[EVP_MAX_MD_SIZE];
    unsigned int md_len;
    EVP_DigestFinal_ex(hashes, md_value, &md_len);
    EVP_MD_CTX_free(hashes);

    if (output_choice == 1) {
        for (unsigned int i = 0; i < md_len; i++) {
            cout << hex << setfill('0') << setw(2) << static_cast<unsigned int>(md_value[i]);
        }
        cout << dec << endl;
    } else if (output_choice == 2) {
        for (unsigned int i = 0; i < md_len; i++) {
            f_out << hex << setfill('0') << setw(2) << static_cast<unsigned int>(md_value[i]);
        }
        f_out << dec << endl;
        f_out.close();
    } else {
        cerr << "Invalid output choice" << endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    char algo[256];
    char input_data[4096];
    char output_filename[256];
    int input_choice;
    int output_choice;

    cout << "Enter the hash algorithm (e.g., sha256, md5): ";
    cin.getline(algo, sizeof(algo));

    // Convert algo to lowercase
    for (int i = 0; algo[i]; i++) {
        algo[i] = tolower(algo[i]);
    }

    cout << "Choose input method:\n";
    cout << "1. Enter text from keyboard\n";
    cout << "2. Read from a file\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> input_choice;
    cin.ignore();  // To consume the newline character left by cin

    if (input_choice == 1) {
        cout << "Enter text to hash (end input with Enter): ";
        cin.getline(input_data, sizeof(input_data));
    } else if (input_choice == 2) {
        cout << "Enter input file path: ";
cin.getline(input_data, sizeof(input_data));

// Debug statement to check the entered file path
cout << "Entered file path: " << input_data << endl;
    } else {
        cerr << "Invalid choice" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Choose output method:\n";
    cout << "1. Display hash on screen\n";
    cout << "2. Save hash to file\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> output_choice;

    if (output_choice == 2) {
        cout << "Enter output file name: ";
        cin.ignore(); // Clear the newline character from the input buffer
        cin.getline(output_filename, sizeof(output_filename));
    } else if (output_choice != 1) {
        cerr << "Invalid choice" << endl;
        exit(EXIT_FAILURE);
    }

    auto start = chrono::high_resolution_clock::now();
    hashes(algo, input_data, output_filename, input_choice, output_choice);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double, milli>(stop - start);
    cout << "\nHash time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
