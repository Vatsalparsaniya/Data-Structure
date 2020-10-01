#include<bits/stdc++.h>
using namespace std;

void lengthOfLCS(string s1,string s2)
{

	// for calculating the length of lcs
	int n=s1.length(),m=s2.length();
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<"\n";

	// for printing the lcs
	string res;
	i=n;j=m;
	while(dp[i][j]!=0)
	{
		if(dp[i][j]==max(dp[i-1][j],dp[i][j-1]))
		{
			if(dp[i][j]==dp[i-1][j])
				i--;
			else
				j--;
		}
		else
		{
			res=s1[i-1]+res;
			i--;
			j--;
		}
	}
	cout<<res;

}

int main()
{
	string s1,s2; cin>>s1>>s2;
	lengthOfLCS(s1,s2);
}