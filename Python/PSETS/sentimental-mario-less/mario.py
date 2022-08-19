# TODO
from cs50 import get_int

blocks = get_int("Height: ")
while blocks < 1 or blocks > 8:
    blocks = get_int("Height: ")

for i in range(0, blocks):
    for j in range(0,blocks - i):
        print(" ", end= "")