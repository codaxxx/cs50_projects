#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) { 

    // initializing variables
    int words = 0;
    int letters = 0;
    int sentences = 0;
    int indexval = 0;
    char sentence[500];

    // inputting strings
    printf("Text: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("%s\n", sentence);

    // for loop to increment chars
    for(int i = 0; i < strlen(sentence); i++) { 
        if(isalpha(sentence[i])) {
            letters++;
        }
    }

    // for loop to increment words
    for (int i = 0; i < strlen(sentence); i++) {
        if(isspace(sentence[i])) {
            words++;
        }
    }

    // for loop to increment sentence count
    for (int i = 0; i < strlen(sentence); i++) {
        if(ispunct(sentence[i])) {
            sentences++;
        }
    }

    // debug statements
    printf("%d\n", letters);
    printf("%d\n", words);
    printf("%d\n", sentences);

/* PSEUDOCODE:
    print message for sentence input, store it as a string / array
    interate over array like in scrabble.c
    increment wordcount by whitespace

    increment letters
    increment sentences by punctuatiion - how?

    so three for loops?x
    use it them to increment over string.

*/


/*
l = letters
w = words, # spaces + 1
s = periods, q, !, etc

coleman-liau index = 
0.0588 * L - 0.296 * S - 15.8

before grade 1
grade 16+

Round score to nearest whole number.

L = average number of letters per 100 words
S = # of sentences per 100 words

*/
    
}