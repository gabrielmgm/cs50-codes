// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Defines a node in the hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Prototypes
bool find_word(node *head, const char *word);
void free_list(node *head);

// Keeps track of the number of words in the dictionary
int total_words = 0;

// Number of buckets in the hash table
const unsigned int NUM_BUCKETS = 26;

// Hash table, organized by first letter and word length
node *hash_table[NUM_BUCKETS][LENGTH];

// Checks if a word is in the dictionary, returns true if found, else false
bool check(const char *word)
{
    int index = hash(word);
    int length = strlen(word) - 1;
    node *current = hash_table[index][length];
    return find_word(current, word);
}

// Searches for a word in a linked list, returns true if found, else false
bool find_word(node *head, const char *word)
{
    if (head == NULL)
    {
        return false;
    }
    if (strcasecmp(head->word, word) == 0)
    {
        return true;
    }
    return find_word(head->next, word);
}

// Hashes a word to an index based on its first letter
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize the hash table with NULL values
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            hash_table[i][j] = NULL;
        }
    }

    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer to hold each word
    char word_buffer[LENGTH + 1];

    // Read each word from the file
    while (fscanf(file, "%s", word_buffer) != EOF)
    {
        // Hash the word to get the index
        int index = hash(word_buffer);
        int length = strlen(word_buffer) - 1;

        // Create a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // Copy word to the new node and set its next pointer to NULL
        strcpy(new_node->word, word_buffer);
        new_node->next = NULL;

        // Insert the node at the beginning of the list in the hash table
        if (hash_table[index][length] == NULL)
        {
            hash_table[index][length] = new_node;
        }
        else
        {
            new_node->next = hash_table[index][length];
            hash_table[index][length] = new_node;
        }

        // Increment word count
        total_words++;
    }

    // Close the dictionary file
    fclose(file);
    return true;
}

// Returns the number of words in the dictionary if loaded, else 0
unsigned int size(void)
{
    return total_words;
}

// Unloads the dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free all linked lists in each bucket of the hash table
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            if (hash_table[i][j] != NULL)
            {
                free_list(hash_table[i][j]);
            }
        }
    }
    return true;
}

// Recursively frees a linked list
void free_list(node *head)
{
    if (head == NULL)
    {
        return;
    }
    free_list(head->next);
    free(head);
}
