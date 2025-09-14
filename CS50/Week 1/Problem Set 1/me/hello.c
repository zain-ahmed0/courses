#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks for the user's name
    string name = get_string("What is your name?: ");

    // Print the user's name
    printf("hello, %s\n", name);
}
