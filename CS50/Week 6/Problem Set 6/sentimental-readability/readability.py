# Function to calculate the letter count
def count_letters(text):
    # Initialize variable
    letters = 0

    # Loop through the text and count the letters
    for i in range(0, len(text)):
        if text[i].isalpha():
            letters += 1

    return letters


# Function to calculate the word count
def count_words(text):
    # Initialize variable
    words = 0

    # Loop through the text and count the words
    for i in range(0, len(text)):
        if text[i] == " ":
            words += 1

    return words + 1


# Function to calculate the sentence count
def count_sentences(text):
    # Initialize variable
    sentences = 0

    # Loop through the text and count the sentences
    for i in range(0, len(text)):
        if text[i] == "?" or text[i] == "!" or text[i] == ".":
            sentences += 1

    return sentences


# Function to calculate the grade
def calculate_grade(letters, words, sentences):
    # L is the average number of letters per 100 words in the text
    L = (letters / words) * 100

    # S is the average number of sentences per 100 words in the text
    S = (sentences / words) * 100

    result = round(0.0588 * L - 0.296 * S - 15.8)

    return result


def main():
    # Prompt the user for a text
    text = input("Text: ")

    # Use the calculate_grade function and return the result
    result = calculate_grade(count_letters(text), count_words(text), count_sentences(text))

    # Output the grade for the text
    if result < 1:
        print("Before Grade 1\n")
    elif result >= 16:
        print("Grade 16+\n")
    else:
        print(f"Grade {result}\n")


if __name__ == "__main__":
    main()
