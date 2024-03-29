#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
// maps user argument to pointer inputString. Declaring variables.
    char *cipher = argv[1];
    char upper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[26] = "abcdefghijklmnopqrstuvwxyz";
    char cipherlower[26];
    char cipherout[500] = "";
    int counter = 0; // for confirming no repeat chars.

// if statements to ensure that cmd line args are adequate
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(cipher) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

// for statement to ensure key is only letters.
    for(int i = 0; i < strlen(cipher); i++) {
        if (isupper(cipher[i]) || islower(cipher[i])) {
            continue;
        }
        else {
            printf("Key must only contain letters.\n");
            return 1;
        }
    }

// for statement to ensure no repeat characters
    for(int i = 0; i < strlen(cipher); i++) {
        for(int j = i + 1; j < strlen(cipher); j++) {
            if (toupper(cipher[j]) == toupper(cipher[i])) {
                printf("Key cannot contain repeated characters.\n");
                return 1;
            }
        }
    }
    
// Prompting for user input to encrypt
    char usrinput[500];
    printf("Plaintext: ");
    scanf("%s", usrinput);

// using for loops to encipher text
    for (int i = 0; i < strlen(usrinput); i++) {
        if (isalpha(usrinput[i]) && isupper(usrinput[i])) {
            for (int j = 0; j < strlen(upper); j++) {
                if (usrinput[i] == upper[j]) {
                    cipherout[i] = toupper(cipher[j]);
                }
            }
        }
        else if (isalpha(usrinput[i]) && islower(usrinput[i])) {
            for (int j = 0; j < strlen(lower); j++) {
                if (usrinput[i] == lower[j]) {
                    cipherout[i] = tolower(cipher[j]);
                }
            }
        }
        else {
            if(ispunct(usrinput[i])){
            cipherout[i] = usrinput [i];
            }
        }
    }

    printf("ciphertext: %s\n", cipherout);

}
