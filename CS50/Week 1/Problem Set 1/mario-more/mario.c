#include <cs50.h>
#include <stdio.h>

void print_spaces(int spaces);

void print_bricks(int bricks);

int main(void)
{
    int height;

    // Keep prompting the user to enter a valid height
    do
    {
        height = get_int("Height?: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        // Calculates the number of spaces for each row
        int numberOfSpaces = (height - 1) - row;

        /*
            Will print the spaces for the left side pyramid
            then the gaps then print the right side pyramid
            then a new line
        */

        print_spaces(numberOfSpaces);

        print_bricks(row);

        printf("  ");

        print_bricks(row);

        printf("\n");
    }
}

// Logic to print the number of spaces
void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

// Logic to print the number of left bricks
void print_bricks(int bricks)
{
    for (int i = 0; i < bricks + 1; i++)
    {
        printf("#");
    }
}
