#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner

    // Check who has higher score and print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        // Printing Tie if both the Players has equal scores
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Initialise score of word
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        // Convert every lower character to upper
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
        }

        // Get the index of word in POINTS by pariting ASCII values of character
        int letterIndex = (int)word[i] % 65;

        // Score of each character in the word
        int letterScore = POINTS[letterIndex];

        // Update score eaual to 0 if it is not an alphabet
        if (!isalpha(word[i]))
        {
            letterScore = 0;
        }

        // Sum all the letter scores to word score
        score += letterScore;
    }

    // Return the total Score of the word
    return score;
}
