// C++ program to print largest contiguous sub-array sum efficiently

#include<bits/stdc++.h> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0;          //max_ending_here is used to look for all positive contigious segments of array
                                                            //max_so_far stores answer to be returned so far
                                                            
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
  

int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n);                     // max_sum stores the largest contigious subarray sum
    cout << "Maximum contiguous sum is " << max_sum;                
    return 0; 
} 
