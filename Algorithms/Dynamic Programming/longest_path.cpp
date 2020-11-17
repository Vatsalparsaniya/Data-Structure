/*

Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) 
such that all cells along the path are in increasing order with a difference of 1.
We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or 
(i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

*/


#include<bits/stdc++.h>
using namespace std;

int maxFromCell(int i,int j,int *matrix,int *dp,int n)
{
	if(i<0 || i>=n || j<0 || j>=n)
		return 0;
	if(*(dp+i*n+j)!=-1)
		return *(dp+i*n+j);
	if (j<n-1 && ((*(matrix+i*n+j) +1) == *(matrix+i*n+j+1))) 
       return *(dp+i*n+j) = 1 + maxFromCell(i,j+1,matrix,dp,n); 
  
    if (j>0 && (*(matrix+i*n+j) +1 == *(matrix+i*n+j-1))) 
       return *(dp+i*n+j) = 1 + maxFromCell(i,j-1,matrix,dp,n); 
  
    if (i>0 && (*(matrix+i*n+j) +1 == *(matrix+(i-1)*n+j))) 
       return *(dp+i*n+j) = 1 + maxFromCell(i-1,j,matrix,dp,n); 
  
    if (i<n-1 && (*(matrix+i*n+j) +1 == *(matrix+(i+1)*n+j))) 
       return *(dp+i*n+j) = 1 + maxFromCell(i+1,j,matrix,dp,n); 
  
    // If none of the adjacent fours is one greater 
    return *(dp+i*n+j) = 1;
}

int main()
{
	int n; cin>>n;
	int matrix[n][n],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>matrix[i][j];
	}
	int dp[n][n];
	memset(dp,-1,sizeof(dp));
	int res=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dp[i][j]==-1)
			{
				dp[i][j]=maxFromCell(i,j,(int*)matrix,(int*)dp,n);
			}
			res=max(res,dp[i][j]);
		}
	}
	cout<<res;
	return 0;
}