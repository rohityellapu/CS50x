import csv
import sys

def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: pythonfile.py filename\n")
    with open(sys.argv[1]) as file:
        read = csv.DictReader(file)
        for row in read:
            print(row)





main()