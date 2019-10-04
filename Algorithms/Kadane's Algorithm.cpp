#include<bits/stdc++.h>
using namespace std;

  
int maxSubArraySum(int array[], int size) 
{ 
    int best= 0;
    int sum = 0;
  
    for (int i = 0; i < size; i++) 
    { 
    sum = max(array[i],sum+array[i]);
    best = max(best,sum);  
    } 
    return best; 
} 
  
/*Driver program to test maxSubArraySum*/
int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 
