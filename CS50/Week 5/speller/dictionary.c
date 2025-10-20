// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 2500;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Calculate hash of word
    int total = hash(word);

    // Create a cursor to traverse the hash table
    node *cursor = table[total];

    while (cursor != NULL)
    {
        // Check if the word is in the dictionary
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // Travel to the next node
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Initialize variables
    int total = 0;

    int length = strlen(word);

    // Loop through each character in the word to calculate the ASCII total
    for (int i = 0; i < length; i++)
    {
        total += toupper(word[i]) - 'A';
    }

    // Add the first character of the word ASCII value to the total
    total += toupper(word[0]) - 'A';

    // Return hashed value
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize variables
    char word[LENGTH + 1];

    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    // Check to see if file isn't at the end
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for a new node
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            return false;
        }

        // Copy the word in the dictionary to the new node
        strcpy(new_node->word, word);

        // Calculate a hash value
        int result = hash(word);

        // Store the new node into the hash table
        new_node->next = table[result];

        table[result] = new_node;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Initialize variable
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        // Create a cursor to traverse the hash table
        node *cursor = table[i];

        while (cursor != NULL)
        {
            count++;

            // Travel to the next node
            cursor = cursor->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Initialize variable
    node *tmp;

    for (int i = 0; i < N; i++)
    {
        // Create a cursor to traverse the hash table
        node *cursor = table[i];

        while (cursor != NULL)
        {
            // Assign cursor to temporary variable to keep track of next node position
            tmp = cursor;

            // Travel to the next node
            cursor = cursor->next;

            free(tmp);
        }
    }
    return true;
}
