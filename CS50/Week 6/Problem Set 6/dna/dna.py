import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Missing command-line argument")

    # Read database file into a variable
    # Initialize rows of people from the database csv file
    rows = []

    with open(sys.argv[1]) as file:
        database = csv.DictReader(file)

        # Get the STR names from the database csv file
        str_names = database.fieldnames[1:]

        # Add each person in the database csv file to the rows array
        for row in database:
            rows.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    # Initialize dictionary for STR name and count
    str_counts = {}

    # Loop through the STR names and initialize a count of 0
    for str_name in str_names:
        str_counts[str_name] = 0

    # Calculate the STR count from the sequence text file
    for str_name in str_counts:
        str_counts[str_name] = longest_match(sequence, str_name)

    # Check database for matching profiles
    for person in rows:
        match = True
        for str_name in str_counts:
            if str_counts[str_name] != int(person[str_name]):
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
