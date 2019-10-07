#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int elem)
{
    int mid;
    if(low<=high)
    {
        mid=low+(high-low)/2;
//        cout<<mid<<endl;        
        if(arr[mid]==elem)
            return mid;
        else if(arr[mid]>elem)
            return binarySearch(arr,low,mid-1,elem);
        else
           return binarySearch(arr,mid+1,high,elem);
    }
    return -1;
}
int main()
{
    //Provided array is sorted else we will have to use sort function.
    int n,elem;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the elements of array:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the elements to be searched:\n";
    cin>>elem;
//    sort(arr,arr+n);
    int index=binarySearch(arr,0,n-1,elem);

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

