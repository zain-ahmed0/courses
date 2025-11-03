# Function to calculate the amount of coins used to give change
def calculate_coins_used(change):
    # Initialize constants
    QUARTER = 25
    DIME = 10
    NICKEL = 5
    PENNY = 1

    # Initialize variables
    quarter_count = 0
    dime_count = 0
    nickel_count = 0
    penny_count = 0

    # The while loop will calculate the amount of coins used to give change
    # Will keep looping till the change amount is equal to 0
    while change > 0:
        if change >= QUARTER:
            change = change - QUARTER
            quarter_count += 1
        elif change >= DIME:
            change = change - DIME
            dime_count += 1
        elif change >= NICKEL:
            change = change - NICKEL
            nickel_count += 1
        elif change >= PENNY:
            change = change - PENNY
            penny_count += 1

    # Calculate and return total amount of coins used to give change
    total = quarter_count + dime_count + nickel_count + penny_count

    return total


def main():
    change_owed = 0

    # Keep prompting the user to enter valid change
    while True:
        try:
            change_owed = int(float(input("Change owed: ")) * 100)
            if change_owed > 0:
                break
        except ValueError:
            pass

    # Print the amount of coins used to give change
    print(f"{calculate_coins_used(change_owed)}")


if __name__ == "__main__":
    main()
