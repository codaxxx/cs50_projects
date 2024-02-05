#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char name[100]; // Assuming a maximum name length of 100 characters
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strcpy(candidates[i].name, argv[i + 1]);
        candidates[i].votes = 0;
    }

    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char name[100]; // Assuming a maximum name length of 100 characters
        printf("Vote: ");
        scanf("%s", name);

        // Check for invalid vote
        if (vote(name) == -1)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of the election
    print_winner();
}

// Update vote totals given a new vote
int vote(char *name)
{
    // Iterate through candidates to find the matching name
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increment the vote count for the matched candidate
            candidates[i].votes++;
            return 0; // Return 0 for a valid vote
        }
    }
    return -1; // Return -1 for an invalid vote
} // purpose: see if a name matches with a name that the used inputted.

// Print the winner (or winners) of the election
void print_winner(void)
{
    // find the max number of votes. Iterate over every candidate. add to max vote
    int max_votes = 0;
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes; // was "==" rather than "="
        } 
    }

    // Print the candidate with the max number of votes.
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }

}
