#include <cs50.h>
#include <stdio.h>

// Initialize constant
#define MAX_SINGLE_DIGIT 9

string valid_card(long card, long checkSum, long length);

long calculate_checksum(long card, long checkSum, long length);

int main(void)
{
    // Initialize variables
    long creditCardNumber;
    long length = 0;

    long checkSum = 0;

    // Keep prompting the user to enter a valid credit card
    do
    {
        creditCardNumber = get_long("CC: ");
    }
    while (creditCardNumber < 0);

    long cardNumberCopy = creditCardNumber;

    // Get the length of the card
    while (cardNumberCopy > 0)
    {
        cardNumberCopy /= 10;
        length++;
    }

    checkSum = calculate_checksum(creditCardNumber, checkSum, length);

    printf("%s", valid_card(creditCardNumber, checkSum, length));
}

long calculate_checksum(long card, long checkSum, long length)
{
    // Initialize variables

    // Numerator and Denominator to calculate the second last digit and every other digit onwards
    long doubleDigitNumerator = 100;
    long doubleDigitDenominator = 10;

    // Numerator and Denominator to calculate the last digit and every other digit onwards
    long singleDigitNumerator = 10;
    long singleDigitDenominator = 1;

    long productFirstDigit = 0;
    long productSecondDigit = 0;

    long doubleDigitTotal = 0;
    long singleDigitTotal = 0;

    // Calculate from the second to last digit and onwards and multiply by 2
    for (long i = 0; i < length; i++)
    {
        long digit = (card % doubleDigitNumerator) / doubleDigitDenominator;

        if ((digit * 2) > MAX_SINGLE_DIGIT)
        {
            productFirstDigit = (digit * 2) / 10;

            productSecondDigit = (digit * 2) % 10;

            doubleDigitTotal = doubleDigitTotal + (productFirstDigit + productSecondDigit);
        }
        else
        {
            doubleDigitTotal = doubleDigitTotal + (digit * 2);
        }

        doubleDigitNumerator *= 100;
        doubleDigitDenominator *= 100;
    }

    // Calculate digits that weren't multiplied by 2 from the last digit
    for (long i = 0; i < length; i++)
    {
        long digit = (card % singleDigitNumerator) / singleDigitDenominator;

        singleDigitTotal = singleDigitTotal + digit;

        singleDigitNumerator *= 100;
        singleDigitDenominator *= 100;
    }

    checkSum = doubleDigitTotal + singleDigitTotal;

    return checkSum;
}

// Function to check if a card is valid
string valid_card(long card, long checkSum, long length)
{
    long firstDigit = card;
    long firstTwoDigits = card;

    // Gets the first digit of the card
    while (firstDigit >= 10)
    {
        firstDigit /= 10;
    }

    // Gets the first two digits of the card
    while (firstTwoDigits >= 100)
    {
        firstTwoDigits /= 10;
    }

    // Validates card against pre-defined rules
    if ((checkSum % 10) == 0)
    {
        if ((length == 13 || length == 16) && firstDigit == 4)
        {
            return ("VISA\n");
        }
        else if (length == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            return ("AMEX\n");
        }
        else if (length == 16 && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
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
