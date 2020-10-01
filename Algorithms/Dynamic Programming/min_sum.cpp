#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int sol(int i,int j,int f,int a[])
{
    if(i==j)
        return dp[i][j][f%2]=0;
    if(f%2==0)
    {
        if(dp[i+1][j][1]==-1)
            dp[i+1][j][1]=sol(i+1,j,f+1,a);
        if(dp[i][j-1][1]==-1)
            dp[i][j-1][1]=sol(i,j-1,f+1,a);
        return dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
    }
    else
    {
        if(a[i]>a[j])
        {
            if(dp[i+1][j][0]==-1)
                dp[i+1][j][0]=sol(i+1,j,f+1,a);
            return dp[i][j][1]=dp[i+1][j][0];
        }
        else
        {
            if(dp[i][j-1][0]==-1)
                dp[i][j-1][0]=sol(i,j-1,f+1,a);
            return dp[i][j][1]=dp[i][j-1][0];
        }
    }
}

int main() 
{
    int t,i; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<sol(0,n-1,0,a)<<"\n";    
    }
    return 0;
}