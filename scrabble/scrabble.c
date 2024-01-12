#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main(void) {
    // arrays for letter and char values.
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int values[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    // initializing variables for user input strings, scores, etc
    char string1[100];
    char string2[100];

    int score1 = 0;
    int score2 = 0;

    // scanning for user input using fgets
    printf("Player 1: ");
    fgets(string1, sizeof(string1), stdin);
    printf("Player 2: ");
    fgets(string2, sizeof(string2), stdin);

    // for loops to iterate over string1 and string2
    for(int i = 0; i<strlen(string1); i++){
        // converting lowercase chars to uppercase
        string1[i] = (char)toupper((int)string1[i]);
        if (string1[i] >= 'A' && string1[i] <= 'Z'){ // ensures no out of bounds values
            score1 += values[((int)string1[i])-'A'];
        }
    }
    for(int i = 0; i<strlen(string2); i++){
        // converting lowercase chars to uppercase
        string2[i] = (char)toupper((int)string2[i]);
        if (string2[i] >= 'A' && string2[i] <= 'Z'){ // ensures no out of bounds values
            score2 += values[((int)string2[i])-'A'];
        }
    }

    // If statements to determine a winner
    if (score1 < score2){
        printf("Player 2 wins!\n");
    }
    
    if (score2 < score1){
        printf("Player 1 wins!\n");
    }

    if (score1 == score2){
        printf("Tie!\n");
    }
}