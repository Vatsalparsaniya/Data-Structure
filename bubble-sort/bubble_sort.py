def bubble_sort(array):
    swapped = True
    while swapped:
        swapped = False
        for indx in range(len(array)-1):
            if array[indx] > array[indx + 1]:
                array[indx], array[indx + 1] = array[indx + 1], array[indx]
                swapped = True


array_test = [21, 4, 1, 3, 20, 25, 6, 21, 14]
print(bubble_sort(array_test))