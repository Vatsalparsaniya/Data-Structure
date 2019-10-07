#include<bits/stdc++.h>
using namespace std;

int minCoinsDP(int a[],int n,int val)
{
	int table[val+1];

	table[0]=0; // if value is zero then zero coins required

	for (int i = 1; i <=val; ++i)
	{
		table[i]=INT_MAX;
		for (int j = 0; j < n; ++j)
		{
			if(i>=a[j])
			{
				int subres=table[i-a[j]];
				if (subres!=INT_MAX && subres+1<table[i])
				{
					table[i]=subres+1;
				}
			}
		}
	}
	return table[val];
}

int minCoinsBFS(int a[],int n,int val)
{
	queue <int> q;
	q.push(val);
	int v[n+1]={0};
	int d=0;
	while(q.size())
	{
		int s=q.size();
		while(s--)
		{
			int p=q.front();
			if(p==0)
				return d;
			q.pop();
			if(v[p] || p<0)
				continue;
			v[p]=1;  
            for (int i = 0; i < n; i++) 
                q.push(p - a[i]);

		}
		d++;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int a[n],i,val;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>val;

	cout<<minCoinsDP(a,n,val)<<endl<<minCoinsBFS(a,n,val);

	return 0;
}