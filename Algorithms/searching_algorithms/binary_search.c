#include<stdio.h>
#include<conio.h>

void main()
{
   int first, last, middle, size, i, sElement, list[100];

 
   printf("Enter the size of the list: ");
   scanf("%d",&size);
 
   printf("Enter %d integer values in Assending order\n", size);
 
   for (i = 0; i < size; i++)
      scanf("%d",&list[i]);
 
   printf("Enter value to be search: ");
   scanf("%d", &sElement);
 
   first = 0;
   last = size - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (list[middle] < sElement)
         first = middle + 1;    
      else if (list[middle] == sElement) {
         printf("Element found at index %d.\n",middle);
         break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
      printf("Element Not found in the list.");
   getch();  
}