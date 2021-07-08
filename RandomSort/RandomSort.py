#!/usr/bin/env python3

import random


def random_sort(arr, iterations: int = -1):
    """Sorts a list by randomly shuffling it until it is sorted.
    :param arr: The list to sort.
    :param iterations: Optional. The number of times to attempt to sort. Will stop
                       sorting when list is sorted or number of iterations has been
                       reached. If not given, defaults to -1 (or infinite iterations).

    >>> arr = []
    >>> random_sort(arr)
    >>> arr
    []

    >>> arr = [1]
    >>> random_sort(arr)
    >>> arr
    [1]

    >>> arr = [5, 2, 7]
    >>> random_sort(arr)
    >>> arr
    [2, 5, 7]

    >>> arr = [9, -1, -29]
    >>> random_sort(arr, 0)
    >>> arr
    [9, -1, -29]
    """
    i = 0
    while not _is_sorted(arr):
        if i == iterations:
            break
        random.shuffle(arr)


def _is_sorted(arr):
    """Validates that the list has been sorted."""
    return all(arr[i] >= arr[i - 1] for i in range(1, len(arr)))


if __name__ == '__main__':
    import doctest
    doctest.testmod()
