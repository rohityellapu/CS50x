# TODO

from cs50 import get_float


def main():
    # Prompt the user for owed change
    change = get_float("Change owed: ")

    # Prompt the user forever untill valid input
    while change < 0:
        change = get_float("Change owed: ")

    # Convert change into number of cents
    cents = change*100

    # Calculate number of quarters
    quarters = calculate_quarters(cents)
    cents -= quarters*25

    # Calculate number of dimes
    dimes = calculate_dimes(cents)
    cents -= dimes*10

    # Calculate number of nickels
    nickels = calculate_nickels(cents)
    cents -= nickels*5

    # Calculate number of pennies
    pennies = calculate_pennies(cents)
    cents -= pennies*1

    # Sum up all the coins
    total_coins = quarters + dimes + nickels + pennies

    # Print the least number of coins required
    print(round(total_coins))

# Calculates the number of quarters by taking cents as input
def calculate_quarters(cents):
    quarter = 25
    if cents >= quarter:
        remainder = cents % quarter
        coins = (cents - remainder)/quarter
        return coins
    else:
        return 0

# Calculates the number of dimes by taking cents as input
def calculate_dimes(cents):
    dime = 10
    if cents >= dime:
        remainder = cents % dime
        coins = (cents - remainder)/dime
        return coins
    else:
        return 0

# Calculates the number of pennies by taking cents as input
def calculate_nickels(cents):
    nickel = 5
    if cents >= nickel:
        remainder = cents % nickel
        coins = (cents - remainder)/nickel
        return coins
    else:
        return 0

# Calculates the number of pennies by taking cents as input
def calculate_pennies(cents):
    penny = 1
    if cents >= penny:
        return cents
    else:
        return 0

main()

