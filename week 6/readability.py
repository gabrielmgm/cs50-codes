def main():
    # Prompt the user for text input
    text = input("Text: ")

    # Calculate the readability grade level using the Coleman-Liau index
    level = coleman_liau(text)

    # Print the corresponding grade level based on the index
    if level >= 16:
        print("Grade 16+")
    elif level < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {level}")

# Function to compute the Coleman-Liau index for a given text
def coleman_liau(text):
    # Initialize counters for letters, words, and sentences
    letters = 0
    words = 0
    sentences = 0

    for char in text:
        if char.isalpha():  # Count alphabetic characters as letters
            letters += 1
        elif char.isspace():  # Count spaces as separators between words
            words += 1
        elif char in ['.', '!', '?']:  # Count punctuation as sentence endings
            sentences += 1

    # Add one to words if the text is not empty (account for the last word)
    if len(text.strip()) > 0:
        words += 1

    # Calculate averages per 100 words
    l = letters / words * 100
    s = sentences / words * 100

    # Return the Coleman-Liau index, rounded to the nearest whole number
    return round(0.0588 * l - 0.296 * s - 15.8)

# Run the main function
main()
