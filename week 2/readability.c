#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototype
int coleman_liau(string text);

int main(void)
{
    // Prompt the user for text input
    string text = get_string("Text: ");

    // Calculate the readability grade level using the Coleman-Liau index
    int level = coleman_liau(text);

    // Print the corresponding grade level based on the index
    if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", level);
    }
}

// Function to compute the Coleman-Liau index for a given text
int coleman_liau(string text)
{
    float index, l, s;
    int letters = 0, words = 1, sentences = 0;
    int size = strlen(text);

    for (int i = 0; i < size; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }

        if (isspace(text[i]))
        {
            words += 1;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }

    l = (float) letters / (float) words * 100;
    s = (float) sentences / (float) words * 100;
    index = round(0.0588 * l - 0.296 * s - 15.8);

    return (int) index;
}