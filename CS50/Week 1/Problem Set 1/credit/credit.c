#include <cs50.h>
#include <stdio.h>

// Initialize constant
const int MAX_SINGLE_DIGIT = 9;

string valid_card(long card, long check_sum, long length);

long calculate_checksum(long card, long check_sum, long length);

int main(void)
{
    // Initialize variables
    long credit_card_number;
    long length = 0;

    long check_sum = 0;

    // Keep prompting the user to enter a valid credit card
    do
    {
        credit_card_number = get_long("CC: ");
    }
    while (credit_card_number < 0);

    long card_number_copy = credit_card_number;

    // Get the length of the card
    while (card_number_copy > 0)
    {
        card_number_copy /= 10;
        length++;
    }

    check_sum = calculate_checksum(credit_card_number, check_sum, length);

    printf("%s", valid_card(credit_card_number, check_sum, length));
}

// Function to calculate the checksum
long calculate_checksum(long card, long check_sum, long length)
{
    // Initialize variables

    // Numerator and Denominator to calculate the second last digit and every other digit onwards
    long double_digit_numerator = 100;
    long double_digit_denominator = 10;

    // Numerator and Denominator to calculate the last digit and every other digit onwards
    long single_digit_numerator = 10;
    long single_digit_denominator = 1;

    long product_first_digit = 0;
    long product_second_digit = 0;

    long double_digit_total = 0;
    long single_digit_total = 0;

    // Calculate from the second to last digit and onwards and multiply by 2
    for (long i = 0; i < length; i++)
    {
        long digit = (card % double_digit_numerator) / double_digit_denominator;

        if ((digit * 2) > MAX_SINGLE_DIGIT)
        {
            product_first_digit = (digit * 2) / 10;

            product_second_digit = (digit * 2) % 10;

            double_digit_total = double_digit_total + (product_first_digit + product_second_digit);
        }
        else
        {
            double_digit_total = double_digit_total + (digit * 2);
        }

        double_digit_numerator *= 100;
        double_digit_denominator *= 100;
    }

    // Calculate digits that weren't multiplied by 2 from the last digit
    for (long i = 0; i < length; i++)
    {
        long digit = (card % single_digit_numerator) / single_digit_denominator;

        single_digit_total = single_digit_total + digit;

        single_digit_numerator *= 100;
        single_digit_denominator *= 100;
    }

    check_sum = double_digit_total + single_digit_total;

    return check_sum;
}

// Function to check if a card is valid
string valid_card(long card, long check_sum, long length)
{
    long first_digit = card;
    long first_two_digits = card;

    // Gets the first digit of the card
    while (first_digit >= 10)
    {
        first_digit /= 10;
    }

    // Gets the first two digits of the card
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }

    // Validates card against pre-defined rules
    if ((check_sum % 10) == 0)
    {
        if ((length == 13 || length == 16) && first_digit == 4)
        {
            return ("VISA\n");
        }
        else if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            return ("AMEX\n");
        }
        else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            return ("MASTERCARD\n");
        }
        else
        {
            return ("INVALID\n");
        }
    }
    else
    {
        return ("INVALID\n");
    }
}
