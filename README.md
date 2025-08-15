# C-aesar Cipher
A command-line tool for encrypting and decrypting text using the Caesar cipher algorithm.

## Overview
This program implements the classical Caesar cipher, a substitution cipher that shifts letters in the alphabet by a specified number of positions. It supports both encryption and decryption, including a brute-force feature to try all possible shifts when the key is unknown.

## Features
- Text encryption with custom shift value
- Text decryption with known shift value
- Automatic testing of all possible shift combinations
- Preserves case sensitivity (uppercase/lowercase)
- Maintains non-alphabetic characters unchanged
- Input validation and error handling

## Project Structure
```
C-aesar/
├── src/
│   ├── main.c
│   └── Methods/
│       ├── caesar.h
│       └── caesar.c
├── Makefile
└── README.md
```

## Dependencies
- GCC compiler
- Make build system
- Standard C libraries:
  - stdio.h
  - stdlib.h
  - string.h

## Building and Running
1. Clone the repository:
```bash
git clone https://github.com/DavidLondo/C-aesar.git
cd C-aesar
```

2. Compile the program:
```bash
make
```

3. Run the program:
```bash
make run
```

4. Clean build files:
```bash
make clean
```

## Usage
The program offers an interactive menu with the following options:
1. Encrypt text
2. Decrypt text
3. Exit

### Encryption
- Enter the text you want to encrypt
- Specify a shift value (1-25)
- Get the encrypted result

### Decryption
Two decryption methods are available:
1. With known shift:
   - Enter the encrypted text
   - Provide the shift value
   - Get the decrypted result
2. Without known shift:
   - Enter the encrypted text
   - View all 25 possible combinations
   - Identify the readable message

## Technical Details

### Caesar Cipher Implementation
The core encryption/decryption function is implemented in `caesar.c`:

```c
char *cipher(char const *text, int shift) {
    char *result = malloc(strlen(text) + 1);
    for (int i = 0; text[i] != '\0'; i++) {
        char character = text[i];
        if (character >= 'A' && character <= 'Z') {
            character = ((character - 'A' + shift) % 26 + 26) % 26 + 'A';
        } else if (character >= 'a' && character <= 'z') {
            character = ((character - 'a' + shift) % 26 + 26) % 26 + 'a';
        }
        result[i] = character;
    }
    return result;
}
```

Key features of the implementation:
- Handles both uppercase and lowercase letters
- Preserves non-alphabetic characters
- Uses modulo arithmetic for wrapping around the alphabet
- Dynamically allocates memory for the result
- Properly handles negative shifts for decryption

### Algorithm Explanation
1. For each character in the input text:
   - If it's an uppercase letter (A-Z):
     - Convert to 0-25 range
     - Apply shift
     - Use modulo to wrap around
     - Convert back to ASCII
   - If it's a lowercase letter (a-z):
     - Same process but with lowercase range
   - Otherwise:
     - Keep character unchanged
2. Return the modified string

## Error Handling
- Input validation for menu choices
- Shift value range checking (1-25)
- Buffer overflow prevention
- Memory management with proper allocation/deallocation

## Author
DavidLondo
