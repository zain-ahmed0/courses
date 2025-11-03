# Function to print the number of spaces
def print_spaces(spaces):
    for i in range(spaces):
        print(" ", end="")


# Function to print the number of bricks
def print_bricks(bricks):
    for i in range(bricks + 1):
        print("#", end="")
    print("\n", end="")


def main():
    # Keep prompting the user to enter a valid height
    while True:
        try:
            height = int(input("Height?: "))
            if height >= 1 and height <= 8:
                break
        except ValueError:
            pass

    for row in range(height):
        # Calculates the number of spaces for each row
        number_of_spaces = (height - 1) - row

        print_spaces(number_of_spaces)

        print_bricks(row)


if __name__ == "__main__":
    main()
