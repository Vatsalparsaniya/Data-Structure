import random

def populate(arr, items):
    for i in range(items):
        arr.append(random.randint(1,items*10))
    return arr


def selectionSort(arr):
    for i in range(0,len(arr)):
        i_minor = i
        for j in range(i+1,len(arr)):
          if arr[j] < arr[i_minor]:
            i_minor = j
        arr[i],arr[i_minor] = arr[i_minor],arr[i]


if __name__ == '__main__':
    arr = []
    items = 10
    populate(arr, items)
    print('Unsorted: ', arr)
    selectionSort(arr)
    print('Sorted: ', arr)
