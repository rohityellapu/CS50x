import csv
import sys

def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: pythonfile.py filename\n")
    f = open(sys.argv[1])
    data = csv.DictReader(f)
    print(data)




main()