# Bubble Sort
import random


def populate(arr, items):
    for i in range(items):
        arr.append(random.randint(1,items*100))
    return arr


def bubbleSort(arr):
    for i in range(len(arr)):
        swapped = False
        for j in range(len(arr) - 1):
            if (arr[j] > arr[j + 1]):
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                swapped = True
        if swapped == False:
            return arr


if __name__ == '__main__':
    arr = []
    items = 10
    populate(arr, items)
    print('Unsorted: ', arr)
    bubbleSort(arr)
    print('Sorted: ', arr)

