def partition(arr, first, last):
    pivot = arr[last]
    i = first - 1
    for j in range(first, last):
        if (arr[j] <= pivot):
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[last] = arr[last], arr[i + 1]
    return (i + 1)

#function to perform quicksort in array
def quickSort(arr, first, last):
    if first < last:
        #pivot is correct position of arr[last]
        pivot = partition(arr, first, last)
        quickSort(arr, first, pivot - 1)
        quickSort(arr, pivot + 1, last)

if __name__=="__main__":
    arr= list(map(int, input().split()))
    n=len(arr)
    quickSort(arr, 0, n-1)
    print (arr)