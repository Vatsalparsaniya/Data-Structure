
#include <stdio.h>
#include <conio.h>
#include <time.h>

int TernS(long int arr[], long int l, long int r, long int x)
{
    if (r >= l)
    {
        int mid1 = l + (r - l) / 3;         // We calculate 2 mid points to divide the array into 3 parts
        int mid2 = mid1 + (r - l) / 3;
        if (arr[mid1] == x)
            return mid1;
        if (arr[mid2] == x)
            return mid2;
        if (arr[mid1] > x)
            return TernS(arr, l, mid1 - 1, x);      // We recursively search the 3 parts 
        if (arr[mid2] < x)
            return TernS(arr, mid2 + 1, r, x);
        return TernS(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

void main()
{
    srand(time(NULL));
    long int i, n, l = 0, r, te, bi;
    clock_t s, e;
    double tertime, bintime;
    printf("Enter the number of elements in the array ");
    scanf("%ld", &n);   // The input is used to randomly generate inputs and decide the number of elements in the array
    long int arr[n], x;
    arr[0] = rand() % 6;
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i - 1] + rand() % 6 + 1;
    }
    x = arr[rand() % n];
    printf("Element chosen to be searched: %ld ", x);
    r = n;
    s = clock();
    te = TernS(arr, l, r, x);
    e = clock();
    tertime = ((double)(e - s)) / (double)(CLOCKS_PER_SEC); // This calculates the time taken to do the ternary search
    s = clock();
    if (te == -1)
        printf("\nTernary Search:  The element(%ld) is not in the array. Time taken to perform the function is %0.10e.", x, tertime);
    else
        printf("\nTernary Search:  The position of %ld is %ld. Time taken to perform the function is %0.10e.", x, te + 1, tertime);
    getch();
}
