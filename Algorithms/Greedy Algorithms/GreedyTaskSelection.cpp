#include<stdio.h>  
void ShowTasks(int p[], int x[], int n) 
{ 
    int i, j; 
  
    printf ("Following tasks are selected :"); 
    i = 0; 
    printf("%d ", i); 
    for (j = 1; j < n; j++) 
    { 
      if (p[j] >= x[i]) 
      { 
          printf ("%d ", j); 
          i = j; 
      } 
    } 
}  
int main() 
{ 
    int p[] =  {1, 6, 8, 4, 10, 5,9,4}; 
    int x[] =  {2, 3, 6, 1, 8, 9,11,7}; 
    int n = sizeof(p)/sizeof(p[0]); 
    ShowTasks(p, x, n); 
    return 0; 
} 