#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 

 
void shuffle(int *a, int n)
{
  int i, t, r;
  for(i=0; i < n; i++) {
    t = a[i];
    r = rand() % n;
    a[i] = a[r];
    a[r] = t;
  }
}
bool is_sorted(int *a, int n)
{
  while ( --n >= 1 ) {
    if ( a[n] < a[n-1] ) return false;
  }
  return true;
}
 
void bogosort(int *a, int n)
{
  while ( !is_sorted(a, n) ) shuffle(a, n);
}
 
int main()
{
  int numbers[] = { 12, 1210, 19, 37, 378, 100 };
  int i;
 
  bogosort(numbers, 6);
  for (i=0; i < 6; i++) printf("%d ", numbers[i]);
  printf("\n");
}
