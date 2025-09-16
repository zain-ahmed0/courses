#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rotate(char character, int key);

int main(int argc, string argv[])
{
    // Input validation for the if statements and for loop
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Loop through the command line input to make sure the argument is a digit
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Prompt the user for the plain text
    string text = get_string("plaintext:  ");

    // Initialize variables
    char cipherText[1024] = "";

    int key = atoi(argv[1]);

    // Loop through each character and apply a shift and store the new character in a new variable
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char character = text[i];

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
char rotate(char character, int key)
{
    int shift = 0;
    char newCharacter;

    if (islower(character))
    {
        shift = ((character - 'a') + key) % 26;
        newCharacter = 'a' + shift;
    }
    else if (isupper(character))
    {
        shift = ((character - 'A') + key) % 26;
        newCharacter = 'A' + shift;
    }
    else
    {
        newCharacter = character;
    }

    return newCharacter;
}
