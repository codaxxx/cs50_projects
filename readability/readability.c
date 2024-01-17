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