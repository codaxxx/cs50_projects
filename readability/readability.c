#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) { 

    // initializing variables
    int words = 0;
    int letters = 0;
    int sentences = 0;
    float l100 = 0.0;
    float s100 = 0.0;
    float indexval = 0.0;
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
        if(sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?') {
            sentences++;
        }
    }

    // calculating average number of letters per 100 words
    l100 = (float)letters / words * 100;

    // calculating average number of sentences per 100 words. 
    s100 = (float)sentences / words * 100;

    // calculating Coleman Liau index value
    indexval = 0.0588 * l100 - 0.296 * s100 -15.8;

    // rounding indexval
    int roundedIndex = (int)(indexval + 0.5);

    // if statements to print desired outputs
    if (roundedIndex < 1) { 
        printf("Before Grade 1\n");
    }
    
    else if (roundedIndex > 15) {
        printf("Grade 16+\n");
    }

    else {
        printf("Grade %d\n", roundedIndex);
    }
    

    /* debug statements
    printf("%d\n", letters);
    printf("%d\n", words);
    printf("%d\n", sentences);
    printf("%f\n", indexval);
    printf("%d\n", roundedIndex);
    */
    }