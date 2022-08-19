# TODO

from cs50 import get_float


def main():
    change = get_float("Change owed: ")
    while change < 0:
        change = get_float("Change owed: ")

    cents = change * 100


def calculate_quarters(cents):
    quarter = 25
    
dime = 10
nickel = 5
penny = 1

total_coins = 0

if total_cents >= quarter:
    total_coins += total_cents % quarter
    total_cents %= quarter
if total_cents >= quarter:
    total_coins += total_cents % quarter
    total_cents %= quarter
if total_cents >= quarter:
    total_coins += total_cents % quarter
    total_cents %= quarter
if total_cents >= quarter:
    total_coins += total_cents % quarter
    total_cents %= quarter
