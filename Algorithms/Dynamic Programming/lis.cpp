#include<bits/stdc++.h>
using namespace std;

int lis_N2(int a[],int n)
{
	if(n==0)
		return 0;
	int lis[n];
	lis[0]=1;
	int ma=1;
	for(int i=1;i<n;++i)
	{
		lis[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if(a[j]<a[i] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
		ma=max(ma,lis[i]);
	}
	return ma;
}

int ceilIndex(int tail[],int l,int r,int key)
{
	while(r-l>1)
	{
		int m=l+(r-l)/2;
		if(tail[m]>=key)
			r=m;
		else
			l=m;
	}
	return r;
}

int lis_NlogN(int a[],int n)
{
	if(n==0)
		return 0;
	int tail[n]={0};
	tail[0]=a[0]; int length=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]<tail[0])
			tail[0]=a[i];
		else if(a[i]>tail[length-1])
			tail[length++]=a[i];
		else
			tail[ceilIndex(tail,-1,length-1,a[i])]=a[i];
	}
	return length;
}

int main()
{
	int n; cin>>n;
	int a[n],i;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<lis_N2(a,n)<<endl<<lis_NlogN(a,n)<<endl;
}