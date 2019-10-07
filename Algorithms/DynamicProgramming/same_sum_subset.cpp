#include <bits/stdc++.h>
using namespace std;

bool sol(int a[],int n,int sum)
{
    if(sum%2==1)
        return false;
    sum=sum/2;    
    bool dp[n+1][sum+1];
    int i,j;
    for(i=0;i<=n;i++)
        dp[i][0]=true;
    for(i=1;i<=sum;i++)
        dp[0][i]=false;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(j<a[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
        }
    }
    return dp[n][sum];
}

int main() 
{
    int t; cin>>t;
    while(t--)
    {
        int n,i; cin>>n;
        int a[n];
        int sum=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sol(a,n,sum))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}