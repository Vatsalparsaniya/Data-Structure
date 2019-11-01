// C++ program to implement interpolation search 
#include<bits/stdc++.h> 
using namespace std; 

int interpolationSearch(int arr[], int n, int x) 
{ 
	
	int lo = 0, hi = (n - 1); 


	while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
	{ 
		if (lo == hi) 
		{ 
			if (arr[lo] == x) return lo; 
			return -1; 
		} 

		int pos = lo + (((double)(hi - lo) / 
			(arr[hi] - arr[lo])) * (x - arr[lo])); 

	
		if (arr[pos] == x) 
			return pos; 

		if (arr[pos] < x) 
			lo = pos + 1; 

	
		else
			hi = pos - 1; 
	} 
	return -1; 
} 


int main()
{
    int n,elem;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    int * arr = new int[n+1];
    cout<<"Enter the elements of array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the elements to be searched:\n";
    cin>>elem;
    
    int index=interpolation_search(arr,n,elem);

    if(index == -1)    
    {
        cout<<"Element is not present in the given array!\n";
    }
    else
    {
        cout<<"Element is present at index "<<index<<" in the given array!\n";
    }

    return 0;
}



// this code is contributed by parth sarthi prasad 
