#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Methods/caesar.h"

int main() {
    printf("\n=================================\n");
    printf("  Caesar Cipher & Decipher Tool\n");
    printf("=================================\n");
    printf("\nWelcome to the Caesar Cipher — Encode and Decode Messages\n\n");

    while (1) {
        printf("\n===============================\n");
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Encrypt text with Caesar Cipher\n");
        printf("2. Decrypt text with Caesar Cipher\n");
        printf("3. Exit\n\n");
        
        int choice;
        printf("Enter your choice: ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("Invalid input! Please enter 1, 2 or 3: ");
            while (getchar() != '\n');
        }
        printf("\n");

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n\n");
            break;
        } else if (choice == 1) {
            char text[256];
            int shift;
            
            printf("Enter the text to encrypt: ");
            while (getchar() != '\n'); // Clear input buffer
            scanf("%255[^\n]", text);
            
            printf("Enter the shift value (1-25): ");
            while (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                printf("Invalid shift! Please enter a number between 1 and 25: ");
                while (getchar() != '\n');
            }
            
            char *encrypted = cipher(text, shift);
            printf("\nEncrypted text: %s\n\n", encrypted);
            free(encrypted);
            
        } else if (choice == 2) {
            char text[256];
            int shift;
            
            printf("Enter the text to decrypt: ");
            while (getchar() != '\n');
            scanf("%255[^\n]", text);
            
            printf("\nDo you want to enter the known shift value?\n");
            printf("(1: Yes - if you know the shift, 0: No - to see all possible combinations)\n");
            
            int use_shift;
            printf("\nEnter your choice (0 or 1): ");
            while (scanf("%d", &use_shift) != 1 || (use_shift != 0 && use_shift != 1)) {
                printf("Invalid input! Please enter 0 or 1: ");
                while (getchar() != '\n');
            }
            
            if (use_shift) {
                printf("\nEnter the shift value (1-25): ");
                while (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                    printf("Invalid shift! Please enter a number between 1 and 25: ");
                    while (getchar() != '\n');
                }
                
                char *decrypted = cipher(text, -shift);
                printf("\nDecrypted text: %s\n\n", decrypted);
                free(decrypted);
            } else {
                printf("\nShowing all 25 possible combinations:\n");
                printf("----------------------------------------\n");
                for (int i = 1; i <= 25; i++) {
                    char *decrypted = cipher(text, -i);
                    printf("Shift %2d: %s\n", i, decrypted);
                    free(decrypted);
                }
                printf("----------------------------------------\n");
                printf("Review the outputs above to find the readable message.\n\n");
            }
        }
    }

    return 0;
}