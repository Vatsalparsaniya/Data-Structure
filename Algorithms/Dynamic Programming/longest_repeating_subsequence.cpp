#include <bits/stdc++.h>
using namespace std;

int solve(string str,int n)
{
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(str[i-1]==str[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}

int main() 
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string str; cin>>str;
        cout<<solve(str,n)<<endl;
    }
	return 0;
}