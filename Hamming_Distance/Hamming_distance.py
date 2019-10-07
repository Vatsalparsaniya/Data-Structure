'''
The Hamming distance between two binary integers is the number
of bit positions that differs.

For example:

    117 = 0 1 1 1 0 1 0 1
     17 = 0 0 0 1 0 0 0 1
      H = 0 + 1 + 1 + 0 + 0 + 1 + 0 + 0 = 3
'''


def hamming(a: int, b: int) -> int:
    """Calculate the Hamming distance between two bit strings"""
    result = str(bin(a ^ b)).count('1')
    return result


assert hamming(117, 117) == 0
assert hamming(17, 117) == 3
assert hamming(117, 17) == 3
assert hamming(1, 2) == 2
assert hamming(16, 15) == 5
