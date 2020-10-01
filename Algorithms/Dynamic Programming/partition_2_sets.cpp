#include<bits/stdc++.h>
using namespace std;

int partitionRec(int a[],int index,int cSum,int totSum)
{
	if(index==-1)
		return abs((2*cSum)-totSum);

	return min(partitionRec(a,index-1,cSum+a[index],totSum),partitionRec(a,index-1,cSum,totSum));
}

int partitionTab(int a[],int n,int sum)
{
	int dp[n+1][sum+1];
	int i,j;
	for(i=0;i<=n;i++)
		dp[i][0]=1;
	for(i=1;i<=sum;i++)
		dp[0][i]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(a[i-1]<=j) // if the item can be included
				dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];

			else // if the element cannot be included
				dp[i][j]=dp[i-1][j];
		}
	}
	int diff=INT_MAX;
	for(i=sum/2;i>=0;i--)
	{
		if(dp[n][i])
		{
			diff=sum-2*i;
			break;
		}
	}
	return diff;
}

int main()
{
	int n; cin>>n;
	int a[n],i,totSum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		totSum+=a[i];
	}
	cout<<partitionRec(a,n-1,0,totSum)<<"\n"<<partitionTab(a,n,totSum);
}