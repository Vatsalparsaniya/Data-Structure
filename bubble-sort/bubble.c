#include <stdio.h>

long array[100005];
 
void bubbleSort(long n)         // Defining 'bubble sort' function.
{
  long i, j, t;
 
  for (i = 0 ; i< n - 1; i++)
  {
    for (j = 0 ; j< n - i - 1; j++)
    {
      if (array[j] > array[j+1]) {

        t=array[j];             // Swapping index j and j+1
        array[j]=array[j+1];
        array[j+1]=t;
      }
    }
  }

  return;
}
 
int main()
{
  long n, i;

  printf("                                         *\n");
  printf("                                       ***\n");
  printf("                                    ******\n");
  printf("                                **********\n");
  printf("                           ***************\n");
  printf("                       SORTING ALGORITHM!!\n\n");
 
  printf("Enter number of elements you want to sort:\n");
  scanf("%ld", &n); printf("\n");

  if (n>100000) {
    printf("Please enter number less than 10⁵ and start again.\n");
    return 0;
  }
 
  printf("Now please input %ld integers:\n", n);
 
  for (i= 0; i< n; i++)
    scanf("%ld", &array[i]);
 
  bubbleSort(n);
 
  printf("\nHere is your sorted list in ascending order:\n");
 
  for (i=0; i< n; i++)
     printf("%ld ", array[i]);
   printf("\n\n This list was sorted using Bubble Sort technique.\n\n");
 
  return 0;
}