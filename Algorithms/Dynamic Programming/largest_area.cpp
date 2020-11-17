#include<bits/stdc++.h>
using namespace std;

int matrix[100][100];

int largest_square_of_1(int n,int m)
{
	int dp[n][m],i,j,ma=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=matrix[i][j];
			else
			{
				if(matrix[i][j]==1)
				{
					dp[i][j]=1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
				}
			}
			ma=max(ma,dp[i][j]);
		}
	}
	return ma;
}

int largest_rec_of_1_with_swapping_of_columns_allowed(int n,int m)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]>0)
				matrix[i][j]=1+matrix[i-1][j];
		}
	}
	for(i=0;i<n;i++)
		sort(matrix[i],matrix[i]+m,greater<int>());
	int ma=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ma=max(ma,(j+1)*matrix[i][j]);
		}
	}
	return ma;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>matrix[i][j];
		}
	}
	cout<<largest_square_of_1(n,m)<<"\n";
	cout<<largest_rec_of_1_with_swapping_of_columns_allowed(n,m)<<"\n";
}