#include<bits/stdc++.h>
#define INFINITY 100000
using namespace std;
int main(void)
{
    int num_vertices,num_edges,i,j,k,a,b,weight;
    cout<<"Enter number of vertex: "<<endl;
    cin>>num_vertices;
    cout<<"Enter number of edges: "<<endl;
    cin>>num_edges;
    long cost[num_vertices][num_vertices] ;
    for(i=0;i<num_vertices;i++)
    {
        for(j=0;j<num_vertices;j++)
        {
            if(i==j)
                cost[i][j] = 0;
            else
                cost[i][j] = INFINITY;
        }
    }
    for(i=0;i<num_edges;i++)
    {
        cout<<"Enter edges and weights: "<<endl;
        cin>>a>>b>>weight;
        cost[a-1][b-1] = weight;
    }
    int edges = num_edges;
    for(i=0;i<num_vertices;i++)
    {
        for(j=0;j<num_vertices;j++)
        {
            if(j==i)
            {
                continue;
            }
            for(k=0;k<num_vertices;k++)
            {
                if(j==k||k==i)
                    continue;
                else
                {
                    if(cost[j][i]+cost[i][k]<cost[j][k])
                    {
                        cost[j][k] = cost[j][i]+cost[i][k];
                    }
                }
            }
        }
    }
    cout<<endl<<endl;
    for(i=1;i<num_vertices;i++)
    {
        cout<<"1->"<<i+1<<" minimum distance is: "<<cost[0][i]<<endl;
    }
    return 0;
}