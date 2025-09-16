#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char character, string key);

int main(int argc, string argv[])
{

    // Input validation for the if statements and for loop
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Loop through the command line input to make sure the argument is a character
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // Initialize variable for validation
    bool test[26] = {false};

    // Loop through the command line input to make sure the argument has no repeated characters
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        int index = toupper(argv[1][i]) - 'A';
        if (test[index])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            test[index] = true;
        }
    }

    // Prompt the user for the plain text
    string text = get_string("plaintext:  ");

    // Initialize variables
    string key = argv[1];

    char cipherText[1024] = "";

    // Loop through each character and apply a shift and store the new character in a new variable
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        int character = text[i];

        char result = rotate(character, key);

        cipherText[i] = result;
    }

    cipherText[strlen(text)] = '\0';

    // Output the cipher text
    printf("ciphertext: %s\n", cipherText);

    printf("\n");

    return 0;
}

// Function to apply shift to character
char rotate(char character, string key)
{
    int shift = 0;
    char newCharacter;

    if (islower(character))
    {
        shift = character - 'a';
        newCharacter = tolower(key[shift]);
    }
    else if (isupper(character))
    {
        shift = character - 'A';
        newCharacter = toupper(key[shift]);
    }
    else
    {
        newCharacter = character;
    }

    return newCharacter;
}
