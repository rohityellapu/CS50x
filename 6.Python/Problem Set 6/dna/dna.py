import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        print('Missing command line arguments')
        return 1

    # TODO: Read database file into a variable

    with open(sys.argv[1]) as csv_file:

        # Reading the STRs and storing them in a list
        strs = csv_file.readline().strip().split(',')[1:]

        # Storing database file in a variable
        dict_reader = csv.reader(csv_file)

        # TODO: Read DNA sequence file into a variable

        with open(sys.argv[2]) as dna_sequence:
            dna = dna_sequence.readline()

        # TODO: Find longest match of each STR in DNA sequence

        # List of Longest Match of str in DNA sequence in number
        longest_matches = []

        # Appending longest str count corresponding to specific str
        for str in strs:
            longest_matches.append(longest_match(dna, str))

        # TODO: Check database for matching profiles

        # For every person in the database
        for person in dict_reader:

            # Initialising found to be true
            found = True

            # For each STR of the person
            for seq in range(len(strs)):

                # If no Match of STR sequence update found to false
                if int(person[seq + 1]) != int(longest_matches[seq]):
                    found = False

            # Return the person name if every STR matche is found
            if found == True:
                return print(person[0])

    return print('No Match')


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
