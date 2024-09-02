#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype
int compute_score(string word);

int main(void)
{
    // Get input from player 1 and player 2
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Compute scores for both players
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Compare scores and determine the winner
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

// Function to compute the score of a given word
int compute_score(string word)
{
    int score = 0;
    int size = strlen(word);
    
    for (int i = 0; i < size; i++)
    {
        if (isalpha(word[i]))
        {
            score += POINTS[tolower(word[i]) - 97];
        }
    }

    return score;
}