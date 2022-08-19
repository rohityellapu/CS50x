# TODO

from cs50 import get_float


def main():
    change = get_float("Change owed: ")
    while change < 0:
        change = get_float("Change owed: ")

    cents = change*100

    quarters = calculate_quarters(700)
    cents -= quarters*25

    dimes = calculate_dimes(cents)
    cents -= dimes*10

    nickels = calculate_nickels(cents)
    cents -= nickels*5

    pennies = calculate_pennies(cents)
    cents -= pennies*1

    total_coins = quarters + dimes + nickels + pennies
    print(total_coins)

def calculate_quarters(cents):
    quarter = 25
    if cents >= quarter:
        remainder = cents % quarter
        coins = (cents - remainder)/quarter
        return coins
    else:
        return 0

def calculate_dimes(cents):
    dime = 10
    if cents >= dime:
        remainder = cents % dime
        coins = (cents - remainder)/dime
        return coins
    else:
        return 0

def calculate_nickels(cents):
    nickel = 5
    if cents >= nickel:
        remainder = cents % nickel
        coins = (cents - remainder)/nickel
        return coins
    else:
        return 0

def calculate_pennies(cents):
    penny = 1
    if cents >= penny:
        remainder = cents % penny
        coins = (cents - remainder)/penny
        return coins
    else:
        return 0

main()

