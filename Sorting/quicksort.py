import random as r

# As quick sort is a divide and conquer algorithm, we would need a pivot in order to
# segregate the list. In the below function we are considering three values. 1st, 2nd and the middle one
# Then taking the median of the three. This will make a difference as taking just any of the three
# can cause slowness, especially if the list if already sorted or inversely sorted.


def get_pivot(list, low, hi):
    mid = (hi + low) // 2
    s = []
    s = sorted([list[low], list[mid], list[hi]])
    if s[1] == list[low]:
        return low
    elif s[1] == list[mid]:
        return mid
    return hi


# The below function will help compartmentalize the data with the use of pivots.
# Sorting will be done recursively on these compartments/partitions by the quick_sort function below.


def partition(list, low, hi):
    pivot_index = get_pivot(list, low, hi)
    pivot_value = list[pivot_index]
    list[pivot_index], list[low] = list[low], list[pivot_index]
    # Swaps will start from the border value below, after value comparisons with pivot_value
    border = low

    for i in range(low, hi + 1):
        if list[i] < pivot_value:
            border += 1
            list[i], list[border] = list[border], list[i]

    list[low], list[border] = list[border], list[low]

    return border


def quick_sort(list):
    # A helper function that will be called recursively to sort the randomly generated list
    def quick_sort_recur(items, low, high):
        if low < high:
            # This is the index after the pivot, where our lists are compartmentalized
            split_index = partition(items, low, high)
            quick_sort_recur(items, low, split_index)
            quick_sort_recur(items, split_index + 1, high)

    quick_sort_recur(list, 0, len(list) - 1)


# Generating random list with elements >= 1 and <= 100 through user defined size
user_gen_list = []
n = int(input("Enter the size of the list: "))
for i in range(n):
    user_gen_list.append(r.randint(1, 100))
print("Generated List: ", user_gen_list)

# Running the sorting algorithm and printing the same
(quick_sort(user_gen_list))
print("Sorted List: ", user_gen_list)

