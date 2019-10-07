/*

The problem is variation of Longest Increasing Subsequence. 
The numbers which are already a part of LIS need not to be changed. 
So minimum elements to change is difference of size of array and number of elements in LIS. 
Note that we also need to make sure that the numbers are integers. 
So while making LIS, we do not consider those elements as part of LIS that cannot form strictly
increasing by inserting elements in middle.

Example { 1, 2, 5, 3, 4 }, we consider length of LIS as three {1, 2, 5}, not as {1, 2, 3, 4}
because we cannot make a strictly increasing array of integers with this LIS.

*/
#include <bits/stdc++.h>
using namespace std;

int maxi(int a[],int n)
{
    int g=a[0],i;
    for(i=1;i<n;i++)
    {
        if(a[i]>g)
            g=a[i];
    }
    return g;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        
        int ans[n];
        ans[0]=1;
        for(i=1;i<n;i++)
        {
            ans[i]=1;
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j] && ans[i]<ans[j]+1 && i-j<=a[i]-a[j])
                    ans[i]=ans[j]+1;
            }
        }
        cout<<n-maxi(ans,n)<<"\n";
    }
	return 0;
}