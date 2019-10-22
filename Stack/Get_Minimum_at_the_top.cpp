
/*You are given an array A of size N. You need to push the elements of the array into a stack and then print minimum in the stack at each pop.Input:
2
5
1 2 3 4 5
7
1 6 43 1 2 0 5

Output:
1 1 1 1 1
0 0 1 1 1 1 1*/




#include <bits/stdc++.h>
using namespace std;
stack<int>_push(int arr[],int n);
void _getMinAtPop(stack<int>s);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    stack<int>mys=_push(arr,n);
	    _getMinAtPop(mys);
	    cout<<endl;
	    
	    
	    
	}
	return 0;
}



stack<int>_push(int arr[],int n)
{
   // your code here
   stack<int>s;
   s.push(arr[0]);
   for(int i=1;i<n;i++){
       if(s.top()<arr[i]){
           s.push(s.top());}
        else{
            s.push(arr[i]);
        }
       
   }//Initial Template for C++


    return s;
    
}

void _getMinAtPop(stack<int>s)
{
    
    while(!s.empty()){
        int c = s.top();
        cout<<c <<" ";
        s.pop();
        
        
    }
}
