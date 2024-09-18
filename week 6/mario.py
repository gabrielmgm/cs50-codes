def main():
    # Prompt the user for a valid height
    while True:
        height = int(input("Height: "))
        if height > 0:
            break
        
    # Print bricks with the specified height
    print_blocks(height)

# Function to print bricks in a pyramid shape
def print_blocks(height):
    for i in range(1, height+1):
        print(" " * (height - i) + "#" * i)
        
main()