# Python program to find nth fibonacci number in O(1) time.
# Using golden ratio formula

import math

def nth_fibonacci(n):
    golden_ratio = 1.6180339887
    f = (golden_ratio**n)/math.sqrt(5)
    res = math.floor(f + 0.5)
    return res

if __name__=='__main__':
    n = int(input("Enter N : "))
    print("Nth fibonacci number : " + str(nth_fibonacci(n-1)))