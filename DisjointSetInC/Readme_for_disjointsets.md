Input Format

Each line of the input looks like one of the following:
• ‘N’ followed by a positive integer n that indicates number of singleton sets to create.
• ‘?’ followed by two positive integers a and b separated by a space, asking if a and b belong to same set.
• ‘S’ followed by a positive integer a, query for representative element of the set that contains a.
• ‘U’ followed by two positive integers a and b separated by a space, indicating union.
• ‘R’ followed by a positive integer a, indicating query for rank of set containing a.
Each of the lines above ends with a ‘\n’ character. All numbers used will fit inside an int.
End of input is indicated by EOF.


Output Format
• If input line was “N n”: No corresponding output.
• If input line was “U a b”: No corresponding output.
• If input line was “? a b”:
– Output −1 if either of a or b is not a valid element.
– Output 0 if a and b belong to different sets.
– Output 1 if a and b belong to the same set.
• If input line was “S a”:
Output the representative element of the set that contains a.
• If input line was “R a”:
Output the rank of a if a is a valid element. Output −1 otherwise.
All output lines end with a ‘\n’ character.
