#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int calculate_grade(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for a text
    string text = get_string("Text: ");

    // Use the calculate_grade function and return the result
    int result = calculate_grade(count_letters(text), count_words(text), count_sentences(text));

    // Output the grade for the text
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
}

// Function to calculate the letter count
int count_letters(string text)
{
    // Initialize variable
    int letters = 0;

    // Loop through the text and count the letters
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// Function to calculate the word count
int count_words(string text)
{
    // Initialize variable
    int words = 0;

    // Loop through the text and count the words
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }

    return words + 1;
}

// Function to calculate the sentence count
int count_sentences(string text)
{
    // Initialize variable
    int sentences = 0;

    // Loop through the text and count the sentences
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++;
        }
    }

    return sentences;
}

// Function to calculate the grade
int calculate_grade(int letters, int words, int sentences)
{
    // L is the average number of letters per 100 words in the text
    float L = ((float) letters / words) * 100;

    // S is the average number of sentences per 100 words in the text
    float S = ((float) sentences / words) * 100;

    int result = round(0.0588 * L - 0.296 * S - 15.8);

    return result;
}
