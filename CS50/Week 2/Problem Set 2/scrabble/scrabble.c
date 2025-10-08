#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Enter word: ");
    string player2 = get_string("Enter word: ");

    // Compute the score of each word
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Output the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to compute the word score
int compute_score(string word)
{
    // Initialize score variable
    int score = 0;

    // Initalize length of word variable
    int length_of_word = strlen(word);

    // Compute score for each character
    for (int i = 0; i < length_of_word; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}
