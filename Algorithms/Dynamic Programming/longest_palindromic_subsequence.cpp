#include<bits/stdc++.h>
using namespace std;

void longestPalindromicSubsequence(string s)
{
	int n=s.length();
	int dp[n][n];
	int i,j;
	int ma=0,index=0;
	for(i=0;i<n;i++)
		dp[i][i]=1;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
			dp[i][i+1]=2;
		else
			dp[i][i+1]=1;
	}
	for(int k=3;k<=n;k++)
	{
		for(i=0;i<=n-k;i++)
		{
			j=i+k-1;
			if(s[i]==s[j])
				dp[i][j]=2+dp[i+1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		}
	}
	cout<<dp[0][n-1];
}

int main()
{
	string s; cin>>s;
	longestPalindromicSubsequence(s);
}