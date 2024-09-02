#include "cs50.h"
#include <stdio.h>

// Function prototype
void print_bricks(int h);

int main(void)
{
    int height;

    // Prompt the user for a valid height
    do
    {
        height = get_int("Height: ");
    } while (height < 1);
    
    // Print bricks with the specified height
    print_bricks(height);
}

// Function to print bricks in a pyramid shape
void print_bricks(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}