#include <cs50.h>
#include <stdio.h>

// Initialize constants

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int calculate_coins_used(int change);

int main(void)
{
    int change_owed;

    // Keep prompting the user to enter valid change
    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    // Print the amount of coins used to give change
    printf("%i\n", calculate_coins_used(change_owed));
}

// Function to calculate the amount of coins used to give change
int calculate_coins_used(int change)
{
    // Initialize variables
    int quarter_count = 0;
    int dime_count = 0;
    int nickel_count = 0;
    int penny_count = 0;

    /*
        The while loop will calculate the amount of coins used to give change
        Will keep looping till the change amount is equal to 0
    */
    while (change > 0)
    {
        if (change >= QUARTER)
        {
            change = change - QUARTER;
            quarter_count++;
        }
        else if (change >= DIME)
        {
            change = change - DIME;
            dime_count++;
        }
        else if (change >= NICKEL)
        {
            change = change - NICKEL;
            nickel_count++;
        }
        else if (change >= PENNY)
        {
            change = change - PENNY;
            penny_count++;
        }
    }

    // Calculate and return total amount of coins used to give change
    int total = quarter_count + dime_count + nickel_count + penny_count;
    return total;
}
