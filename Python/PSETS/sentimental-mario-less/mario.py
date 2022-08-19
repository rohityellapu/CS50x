# TODO
from cs50 import get_int

# Get the height of the mario pyramid from user
height = get_int("Height: ")

# Prompt the user forever until valid height number
while height < 1 or height > 8:
    height = get_int("Height: ")

# For each row in the pyramid
for i in range(height):
    # For each column in the pyramid
    for j in range(height-1, -1, -1):
        # Print space
        if j > i:
            print(" ", end="")
        # Print blocks
        else:
            print("#", end="")
    # Print next line
    print()
