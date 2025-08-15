#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"

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

char *decipher(char const *text, int shift){
    return cipher(text, shift);
}