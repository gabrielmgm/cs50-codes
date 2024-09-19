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
    letters = 0
    words = 1
    sentences = 0

    for letter in text:
        if letter.isalpha():
            letters += 1
        elif letter.isspace():
            words += 1
        elif letter == '.' or letters == '!' or letter == '?':
            sentences += 1

    l = letters / words * 100
    s = sentences / words * 100
    return round(0.588 * l - 0.296 * s - 15.8)