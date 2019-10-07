#include<bits/stdc++.h>
using namespace std;

int minAttempts(int n,int k)
{
	int dp[n+1][k+1];
	int i,j,p;
	for(i=1;i<=n;i++)
	{
		dp[i][1]=1;
		dp[i][0]=0;
	}
	for(i=1;i<=k;i++)
		dp[1][i]=i;

	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			for(p=1;p<=j;p++)
			{
				int res=1+max(dp[i-1][p-1],dp[i][j-p]);
				dp[i][j]=min(dp[i][j],res);
			}
		}
	}
	return dp[n][k];
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k; cin>>n>>k;
		cout<<minAttempts(n,k)<<endl;
	}
}