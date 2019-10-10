#Quick Sort
import random

def populate(arr, items):
    for i in range(items):
        arr.append(random.randint(1,items*100))
    return arr

def partition(arr,low,high): 
    i = (low-1)
    pivot = arr[high]
    for j in range(low , high): 
        if   arr[j] < pivot: 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i]   
    arr[i+1],arr[high] = arr[high],arr[i+1]  #swap 
    return (i+1) 

def quick_sort(arr,low,high): 
    if low < high:  
        pi = partition(arr,low,high) 
        quick_sort(arr, low, pi-1) 
        quick_sort(arr, pi+1, high)

if __name__ == '__main__':
    arr = []
    items = 20
    populate(arr, items)
    print('Unsorted: ', arr)
    quick_sort(arr, 0, items-1)
    print('Sorted: ', arr)