Lab 1: Coding DES, AES using cryptopp library
A. Required:
+) Mode of operations:
  - Select mode from screen (using switch case)
  - Support modes:  ECB, CBC, OFB, CFB, CTR, XTS, CCM, GCM.
+) Funtions: Key generation, encryption, decryption function:
   Select from screen (using command-line or GUI)
+) Inputs:
  - Secret key,  Initialization Vector IV, and nonce,..
  Select from screen (using command-line or GUI)
  Case 1: Secret key and IV are randomly chosen for each run time
  Case 2: Input Secret Key and IV from file (using file name/)
- Plaintext
    Case 1: Input from screen;
    Case 2: From files (using file name);
    - Support Vietnamse (using setmode, UTF-8)
- Ciphertext
    Case 1: Input from screen;
    Case 2: From files (using file name);
    - Support Vietnamese (using setmode, UTF-8)
+) Output (hex/base64 encode, binary):
   - display in screen;
   - write to file;
 
Report Lab 1
Write your report in word file including:
  1. Report your hardware resources;
  2. Report computation performance on Windows and Linux (in tabe with capture image on running your program);
    - Generate a set of different input sizes (at least 6 inputs in size KBs up to MBs)
    - Execute your code and check the computation time on average 10 000 running times;
    - Summarize the results in a tables including: size of input, OS (Windows, Linux), encryption time and decryption time.
    - Do a comparison and your comments on both input size and OS;
 
Lab 2: Coding AES using only C++ without other cryptographic external libraries;
Required:
+) Plaintext:
    - Input from screen;
    - Support Vietnamese (using setmode, UTF-8)
+) Mode of operations
     Using CBC mode
+) Secret key and Initialization Vector (IV)
     Input Secret Key and IV from screen
Report Lab 2
Write your report in word file including:
  1. Report your hardware resources;
  2. Report computation performance on Windows and Linux (in tabe with capture image on running your program);
    - Generate a set of different input sizes (at least 6 inputs in size KBs up to MBs)
    - Execute your code and check the computation time on average 10 000 running times;
    - Summarize the results in a tables including: size of input, OS (Windows, Linux), encryption time and decryption time.
    - Do a comparison and your comments on both input size and OS;
 
Lab 3: RSA-OAEP Cipher using CryptoPP
Required:
+) Funtions:Key generation; Encryption; Decryption function (using command-line or GUI)
1) Key generation
  Public Key, Privae  Key;
  Save to files (DER, PEM);
2) Encryption
+) Plaintext:
    - Support Vietnamese (UTF-8)
    - Input from screen or from file (using command-line or GUI)
+) Secret key/public key
    - The keys load from files (command-line or GUI)
    - The public key: >= 3072 bits
+) Save to file/ print to screen with diferent format (BIN, HEX, BASE64)
3) Decryption
+) Ciphertext:
    - Input from screen or from file (command-line or GUI)
+) Secret key/public key
    - The keys load from files (command-line or GUI)
    - The public key: >= 3072 bits
+) Recover text: Save to file/ print to screen
 
Report Lab 3
Write your report in word file including:
  1. Report your hardware resources;
  2. Report computation performance on Windows and Linux (in table with capture image on running your program);
    - Generate a set of different input sizes (at least 3 inputs in size KBs up to MBs)
    - Execute your code and check the computation time on average 10 000 running times;
    - Summarize the results in a tables including: size of input, OS (Windows, Linux), encryption time and decryption time.
    - Do a comparison and your comments on both input size and OS;
 
 
Note for task 1,2,3 implementation in order
- Implementation the functions, and then export to .dll/.so
- Using Python/C# to create GUI
LAB 4: PKI and Hash Functions
Task 4.1: Hash Functions
Required:
+) Separation all hash functions(using command-line or GUI)
SHA224, SHA256, SHA384, SHA512, SHA3-224, SHA3-256, SHA3-384, SHA3-512, SHAKE128,SHAKE256
+) Plaintext:
    - Support Vietnamese (UTF-8)
    - Input from screen or from file (using command-line or GUI)
+) Digest:
    - may choose digest output length d for SHAKE128,SHAKE256 from command-line arguments;
    - digest should be encoded as hex string án save to file or print to screen;
+) OS platforms
  - Your code can compile on both Windows and Linux;
+) Performance
  - Report your hardware resources
  - Report computation performance for all operations on both Windows and Linux with different input size;
Task 4.2: PKI and digital certificate
code your tool using cryptopp or openssl that can
    - Parse all the fields of a X.509 certificate, including subject name, issuer name, subject public key, signature, signature algorithms and its parameters, purposes, valid from and valid to dates, ...
    - Check the validate of the signature;
  Required:
       Input certificate from the file inform PEM (Base64) or DER (binary);
       Output: return subject public key if the signature is valid and null otherwise;
LAB 4.3: Collision and length extension attacks on Hash functions
Required:
+) MD5 collision attacks
+) Two collision messages have the same prefix string
- Generate yourself prefix string
- Compute the two output files that have the same MD5 digest (using hashclash tool)
+) Two different C++ programs but have the same MD5;
- Code yourself two short C++ programs
- Compiler your codes code1, code2
- Run hashclash to generate two program with the same MD5 digest
Note: It takes long time to generate the output.
Task 4.4 Length extension attacks on MAC  in form: H(k||m), k is secret key
+) show length extension attacks on MAC using SHA1, SHA256, SHA512 using hashpump tool;
+) Coding self programs that can attacks on MAC using SHA256 (for bonus 5/100 points)
- Automatic compute the padded part for any input (k||m);
- Compute the digest using length extension attacks with any extend string;
Task 4.5 attack on digital certificate (for bonus 10/100 points)
- generate a digital certificate using MD5 and RSA using openssl;
- compute an other digital certificate with the same signature but other subject using hashclash tool
 
Report Lab 4
Write your report in word file including:
  1. Report your hardware resources;
  2. Report computation performance on Windows and Linux (in table with capture image on running your program);
    - Generate a set of different input sizes (at least 5 inputs in size MBs up to GBs) for hash function
    - Execute your code and check the computation time on average 1000 running times for hash function;
    - The other result files for other tasks;  
    - Summarize the results in a tables including: size of input, OS (Windows, Linux), operation time.
    - Do a comparison and your comments on both input size and OS;
 
LAB 5: Digital signature with CryptoPP/Openssl
Required:
+) Algorithm: ECDSA, RSASS-PSS
+) Three module: key generation, signing and the verify functions (using command-line or GUI)
1) Key generation
  Publickey, Privae  Key;
  Save to file s (ber, pem);
2) signing function
    - May adopt library or direct compute from formulas.
    - Deploy directly from formulas will get 15/100 bonus points.
+) Message to sign
    - Input from file or screen
    - Support Vietnamese (using UTF-8)
+) secret key
   - Input from file
3) Verify function
+) Message and signature
    - Input from files
    - Support Vietnamese (using UTF-8)
+) public key key
   - Input from file
 
4) ECC curve:  should select from standard curves
+) Secret key/public key
    - The keys load from files (for both two functions and arguments in C++/C# in terminal or GUI)
    - The public key: >= 256 bits
+) OS platforms
  - Your code can compile on both Windows and Linux;
Report Lab 5
Write your report in word file including:
  1. Report your hardware resources;
  2. Report computation performance on Windows and Linux (in table with capture image on running your program);
    - Report computation performance for all operations on both Windows and Linux with different input size;
    on average 1000 running times for hash function;
    - Summarize the results in a tables including: size of input, OS (Windows, Linux), operation time (sign, verify).
    - Do a comparison and your comments on both input size and OS;
