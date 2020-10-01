#include<bits/stdc++.h>
using namespace std;

void longestPalindromicSubstring1(string s) // time complexity:O(N^2) space complexity:O(N^2)
{
	int n=s.length();
	int dp[n][n];
	int i,j;
	int ma=0,index=0;
	for(i=0;i<n;i++)
		dp[i][i]=1;
	ma=1;
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=1;
			ma=2;
			index=i;
		}
		else
			dp[i][i+1]=0;
	}
	for(int k=3;k<=n;k++)
	{
		for(i=0;i<=n-k;i++)
		{
			j=i+k-1;
			if(dp[i+1][j-1]==1 && s[i]==s[j])
			{
				dp[i][j]=1;
				ma=k;
				index=i;
			}
			else
				dp[i][j]=0;
		}
	}
	cout<<ma<<"\n"<<s.substr(index,ma);
}

void longestPalindromicSubstring2(string s)
{
	int maxLength=1,start=0,n=s.length();
	int low,high,i;
	for(i=1;i<n;i++)
	{
		// all even length palindromes
		low=i-1;
		high=i;
		while(low>=0 && high<n && s[low]==s[high])
		{
			if(high-low+1>maxLength)
			{
				start=low;
				maxLength=high-low+1;
			}
			++high;
			--low;
		}

		// all odd length palindromes
		low=i-1;
		high=i+1;
		while(low>=0 && high<n && s[low]==s[high])
		{
			if(high-low+1>maxLength)
			{
				start=low;
				maxLength=high-low+1;
			}
			++high;
			--low;
		}
	}
	cout<<s.substr(start,maxLength);
}

int main()
{
	string s; cin>>s;
	longestPalindromicSubstring1(s);
	cout<<endl;
	longestPalindromicSubstring2(s);
}