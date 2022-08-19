# TODO
from cs50 import get_int

height = get_int("Height: ")
while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    for j in range(height-1, 0, -1):
        print(j)
        if j >= i:
            print(" ", end= "")
        else:
            print("#", end="")
    print()