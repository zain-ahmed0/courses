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

    // Initialize length of the number variable
    int length_of_number = strlen(argv[1]);

    // Loop through the command line input to make sure the argument is a digit
    for (int i = 0; i < length_of_number; i++)
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
    char cipher_text[1024] = "";

    int key = atoi(argv[1]);

    // Initalize length of text variable
    int length_of_text = strlen(text);

    // Loop through each character and apply a shift and store the new character in a new variable
    for (int i = 0; i < length_of_text; i++)
    {
        char character = text[i];

        char result = rotate(character, key);

        cipher_text[i] = result;
    }

    cipher_text[length_of_text] = '\0';

    // Output the cipher text
    printf("ciphertext: %s\n", cipher_text);

    printf("\n");

    return 0;
}

// Function to apply shift to character
char rotate(char character, int key)
{
    int shift = 0;
    char new_character;

    if (islower(character))
    {
        shift = ((character - 'a') + key) % 26;
        new_character = 'a' + shift;
    }
    else if (isupper(character))
    {
        shift = ((character - 'A') + key) % 26;
        new_character = 'A' + shift;
    }
    else
    {
        new_character = character;
    }

    return new_character;
}
