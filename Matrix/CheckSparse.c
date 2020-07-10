#include <stdio.h>
#define SIZE 3

int main()
{
    int A[SIZE][SIZE];
    int row, col, total=0;

    printf("Enter elements in matrix of size 3x3: \n");
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            scanf("%d", &A[row][col]);
        }
    }

    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(A[row][col] == 0)
            {
                total++;
            }
        }
    }

    if(total >= (row * col)/2)
    {
        printf("\nThe given matrix is a Sparse matrix.");
    }
    else
    {
        printf("\nThe given matrix is not Sparse matrix.");
    }

    return 0;
}
