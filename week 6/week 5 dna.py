import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Invalid")

    # TODO: Read database file into a variable
    file = open(sys.argv[1], "r")
    reader = csv.DictReader(file)
    database = list(reader)

    # TODO: Read DNA sequence file into a variable
    f = open(sys.argv[2], "r")
    DNA = f.read()

    # TODO: Find longest match of each STR in DNA sequence
    STR = []
    for i in range(1, len(reader.fieldnames)):
        STR.append(longest_match(DNA, reader.fieldnames[i]))

    # TODO: Check database for matching profiles
    cot = 0
    for i in range(len(database)):
        mat = 0
        for j in range(1, len(reader.fieldnames)):
            if STR[j - 1] == int(database[i][reader.fieldnames[j]]):
                mat += 1
            if mat == len(reader.fieldnames) - 1:
                print(database[i]["name"])
                cot += 1
    if cot == 0:
        print("No match")
    file.close()
    f.close()
    return


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