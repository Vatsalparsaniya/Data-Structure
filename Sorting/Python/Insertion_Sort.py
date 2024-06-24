#Insertion Sort
import random

def populate(arr, items):
    for i in range(items):
        arr.append(random.randint(1,items*100))
    return arr

def insertion_sort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i-1
        while j>=0 and key<arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key

if __name__ == '__main__':
    arr = []
    items = 20
    populate(arr, items)
    print('Unsorted: ', arr)
    insertion_sort(arr)
    print('Sorted: ', arr)