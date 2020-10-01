#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int parent[100][100];
int ans[100]; int k;
int a[100];

int rec(int l,int r)
{
	if(l+1>=r) // 0 or 1 element
		return 0;

	int &ret=dp[l][r];
	if(ret!=-1)
		return ret;

	ret=INT_MAX;
	int bestIndex;
	for(int i=l+1;i<r;i++)
	{
		int p=rec(l,i)+rec(i,r)+(a[r]-a[l]);
		if(p<ret)
		{
			ret=p;
			bestIndex=i;
		}
	}

	parent[l][r]=bestIndex;
	return ret;
}

void back(int l,int r)
{
	if(l+1>=r)
		return;

	ans[k++]=a[parent[l][r]];
	back(l,parent[l][r]);
	back(parent[l][r],r);
}

int main()
{
	int n,i; cin>>n;
	int m; cin>>m;
	int a[m+2];
	a[0]=0;
	a[m+1]=n;
	for(i=1;i<=m;i++)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	memset(parent,-1,sizeof(parent));
	int best=rec(0,n-1);
	k=0;
	back(0,n-1);
	for(i=0;i<k;i++)
		cout<<ans[i]<<" ";
}