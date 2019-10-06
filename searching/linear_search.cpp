#include<bits/stdc++.h>
using namespace std;
int linear_search(int arr[],int n,int elem)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==elem)
            return i;
    }
    return -1;
}
int main()
{
    int n,elem;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the elements of array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the elements to be searched:\n";
    cin>>elem;
    
    int index=linear_search(arr,n,elem);

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
