#include "cs50.h"
#include <stdio.h>

// Function prototype
int minimum_coins(int change);

int main(void)
{
    int change;
    int coins;

    // Prompt the user for the amount of change until a non-negative value is provided
    do
    {
        change = get_int("Change owed: ");
    } while (change < 0);
    
    // Calculate the minimum number of coins required and store it
    coins = minimum_coins(change);

    printf("%d\n", coins);
}

// Function to calculate the minimum number of coins
int minimum_coins(int change)
{
    int coins = 0;

    coins += change / 25;
    change %= 25;

    coins += change / 10;
    change %= 10;

    coins += change / 5;
    change %= 5;

    coins += change / 1;
    change %= 1;

    return coins;
}