# TODO

from cs50 import get_float


def main():
    change = get_float("Change owed: ")
    while change < 0:
        change = get_float("Change owed: ")

    cents = change*100

    quarters = calculate_quarters(cents)
    cents -= quarters*25
    print(quarters)
    dimes = calculate_dimes(cents)
    cents -= dimes*10
    print(dimes)
    nickels = calculate_nickels(cents)
    cents -= nickels*5
    print(nickels)
    pennies = calculate_pennies(cents)
    cents -= pennies*1
    print(cents)
    total_coins = quarters + dimes + nickels + pennies
    print(total_coins)

def calculate_quarters(cents):
    quarter = 25
    if cents >= quarter:
        return cents%quarter
    else:
        return 0

def calculate_dimes(cents):
    dime = 10
    if cents >= dime:
        return cents%dime
    else:
        return 0

def calculate_nickels(cents):
    nickel = 5
    if cents >= nickel:
        return cents%nickel
    else:
        return 0

def calculate_pennies(cents):
    penny = 1
    if cents >= penny:
        return cents%penny
    else:
        return 0

main()

