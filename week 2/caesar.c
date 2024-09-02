#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions prototype
bool is_digit(string text);
void caesar(string text, int key);

int main(int argc, string argv[])
{
    // Check if the user provided exactly one command-line argument and if it's a valid digit
    if (argc != 2 || !is_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the command-line argument (key) to an integer
    int key = atoi(argv[1]);

    // Get the plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using Caesar cipher and print the result
    printf("ciphertext: ");
    caesar(plaintext, key);

    return 0;
}

// Function to check if a string consists only of digits
bool is_digit(string text)
{
    int size = strlen(text);
    for (int i = 0; i < size; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to apply the Caesar cipher to a given text using a specified key
void caesar(string text, int key)
{
    int size = strlen(text);

    for (int i = 0; i < size; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                printf("%c", ((text[i] - 64 + key) % 26) + 64);
            }
            else
            {
                printf("%c", ((text[i] - 96 + key) % 26) + 96);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
}