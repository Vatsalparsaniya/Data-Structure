#include "stdio.h"

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);

        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int index = low - 1;

    for(int i = low; i <= high - 1; i++) {
        if(arr[i] < pivot) {
            index++;
            swap(&arr[index], &arr[i]);
        }
    }
    swap(&arr[index + 1], &arr[high]);
    return index + 1;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int arr[] = {9, 8, 7, 6, 5};
    int arraySize = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, arraySize - 1);
    printf("Sorted Array:\n");
    for(int i = 0; i < arraySize; i++) {
        printf("%d", arr[i]);
    }
}