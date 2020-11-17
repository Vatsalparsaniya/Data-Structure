#include<bits/stdc++.h>
using namespace std;

int dp[10000][10000];

int countMemo(int a[],int n,int val) 
{ 
	if(val==0)
		return 1;
	if(val<0)
		return 0;
	if(n<=0 && val>=1)
		return 0;
	if(dp[n][val]==-1)
		dp[n][val]=countMemo(a,n-1,val)+countMemo(a,n,val-a[n-1]);
	return dp[n][val];
} 

int countTabulation(int a[],int n,int val)
{
	int table[val+1][n];
	int i,j;
	for(i=0;i<n;i++)
		table[0][i]=1;

	for(i=1;i<=val;i++)
	{
		for(j=0;j<n;j++)
		{
			int x=i-a[j]>=0?table[i-a[j]][j]:0;
			int y=j>=1?table[i][j-1]:0;
			table[i][j]=x+y;
		}
	}
	return table[val][n-1];
}
 
int main() 
{ 
    int t; cin>>t;
    while(t--)
    {
        int n,i; cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        int val; cin>>val;
        memset(dp,-1,sizeof(dp));
        cout<<countMemo(arr,n,val)<<"\n";
        cout<<countTabulation(arr,n,val)<<"\n";
    }
	return 0; 
} 
