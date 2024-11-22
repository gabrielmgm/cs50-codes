def main():
    # Prompt the user for a valid height
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                break
        except ValueError:  # Handle non-integer input gracefully
            pass

    # Print bricks with the specified height
    print_blocks(height)

# Function to print bricks in a pyramid shape
def print_blocks(height):
    for i in range(1, height + 1):
        # Print spaces and bricks for each row
        print(" " * (height - i) + "#" * i)

main()
