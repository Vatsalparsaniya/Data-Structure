#include<bits/stdc++.h>
using namespace std;

void editDist(string s1,string s2)
{
	// for printing the minimum number of operations required
	int n=s1.length(),m=s2.length();
	int dp[n+1][m+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else
			{
				if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<"\n";

	// for printing the sequence of operations
	i=n,j=m;
	while(dp[i][j]!=0)
	{
		if(s1[i-1]==s2[j-1])
		{
			i--;
			j--;
		}
		else
		{
			if(dp[i][j]==1+dp[i-1][j])
			{
				cout<<"delete "<<s1[i-1]<<"\n";
				i--;
			}
			else if(dp[i][j]==1+dp[i][j-1])
			{
				cout<<"insert "<<s2[j-1]<<"\n";
				j--;
			}
			else
			{
				cout<<"replace "<<s1[i-1]<<" with "<<s2[j-1]<<"\n";
				i--;
				j--;
			}
		}
	}
}

int main()
{
	string s1,s2; cin>>s1>>s2;
	editDist(s1,s2);
	return 0;
}