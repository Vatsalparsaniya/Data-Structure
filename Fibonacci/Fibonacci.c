//Fibonacci Series using Recursion

#include<stdio.h>

int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}

int main ()
{
  int n;
  printf("Enter n where n represent the n Fibonacci term:\n");
  scanf("%d", &n);
  printf("The n Fibonacci term is: %d\n", fib(n));

  return 0;
}
