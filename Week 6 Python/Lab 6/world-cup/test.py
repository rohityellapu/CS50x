import csv
import sys


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: pythonfile.py filename\n")
    teams = []
    counts = {}
    with open(sys.argv[1]) as file:
        read = csv.DictReader(file)
        for row in read:
            row['rating'] = int(row['rating'])
            teams.append(row['team'])
            counts[row['team']] = 0
    print(teams, counts)


main()
