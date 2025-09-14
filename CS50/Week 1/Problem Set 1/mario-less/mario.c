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
    while (height < 1);

    for (int row = 0; row < height; row++)
    {
        // Calculates the number of spaces for each row
        int numberOfSpaces = (height - 1) - row;

        print_spaces(numberOfSpaces);

        print_bricks(row);
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

// Logic to print the number of bricks
void print_bricks(int bricks)
{
    for (int i = 0; i < bricks + 1; i++)
    {
        printf("#");
    }
    printf("\n");
}
