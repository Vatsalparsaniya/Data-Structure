//Radix Sort Program in C++
//Time complexity is O(N*k) where N = num_elements and k = number of digits in maximum number present in input.
//Space complexity if O(N)
/*-------------Radix Sort-------------*/

#include<bits/stdc++.h>
using namespace std;

int getMaxNum(vector<int> &num_arr)
{
    int max=num_arr[0];
    int size = num_arr.size();
    for(int i=1;i<size;i++)
    {
        if(num_arr[i]>max)
            max = num_arr[i];
    }
    return max;
}

void countSort(vector<int> &num_arr, int exp)        // Function to sort numbers according to the digit exp
{
    vector<int> result(num_arr.size());
    vector<int> freq(10,0);        //Array to count frequency of digits. //Initialised from 0.
    
    int size = num_arr.size();     //Size of input array.
    
    for(int i=0;i<size;i++)
    {
        freq[(num_arr[i]/exp)%10]++;
    }
    
    for(int i=1;i<10;i++)
    {
        freq[i] += freq[i-1];          //Now freq[] contains actual position of these digits in output.
    }
    
    for(int i=size-1;i>=0;i--)            //Generating the output result array according to the current digit considered.
    {
        result[freq[ (num_arr[i]/exp)%10 ] - 1] = num_arr[i]; 
        freq[ (num_arr[i]/exp)%10 ]--;                        //Decreasing the frequency of the digit once used.
    }
    
    for (int i = 0; i < size; i++) 
        num_arr[i] = result[i]; 
        
    return;
}

void radixSort(vector<int> &num_arr)
{
    int max_num;
    max_num = getMaxNum(num_arr);       //Getting the maximum number out of vector.
    
    int exp;
    for(exp=1;max_num/exp>0;exp*=10)
    {
        countSort(num_arr,exp);
    }
    
}

int main(void)
{
    int num_elements;
    cout<<"Enter number of elements: ";
    cin>>num_elements;              
    vector<int> num_arr(num_elements);    //Declaring vector of elements.
    
    for(int i=0;i<num_elements;i++)
    {
        cout<<"Enter "<<(i+1)<<"th number: ";
        cin>> num_arr[i];             //Getting the input numbers.
    }
    
    radixSort(num_arr);
    
    cout<<"The sorted array is: ";
    
    for(int i=0;i<num_elements;i++)
    {
        cout<<num_arr[i]<<" ";
    }
    return 0;
    
}