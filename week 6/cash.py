def main():
    # Prompt the user for the amount of change until a non-negative value is provided
    while True:
        change = float(input("Change owed: "))
        if change > 0:
            break

    # Calculate the minimum number of coins required and store it
    coins = minimum_coins(change)
    
    print(coins)
    
# Function to calculate the minimum number of coins
def minimum_coins(change):
    change = round(change * 100)
    coins = 0
    
    while change > 0:
        if change >= 25:
            change -= 25
            coins += 1
        elif change >= 10:
            change -= 10
            coins += 1
        elif change >= 5:
            change -= 5
            coins += 1
        elif change >= 1:
            change -= 1
            coins += 1      
              
    return coins

main()