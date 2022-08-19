# TODO

from cs50 import get_float

change = get_float("Change owed: ")

total_cents = change * 100

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
