#include<bits/stdc++.h>
#include <vector>
#define INFINITY 100000
using namespace std;
void ShortestPathDistance(long *cost,int num_vertices,bool * visited)
{
    long dist[num_vertices] = {100000};
    vector <int> distances;
    long i,cnt = 2,j,u;
    for(i=1;i<num_vertices;i++)
    {
        dist[i] = *((cost)+i);
        distances.push_back(dist[i]);
    }
    visited[0] = true ; dist[0] = 0;
    long min = INFINITY;
    while(cnt<=num_vertices)
    {
        min = INFINITY;
        for(j=1;j<num_vertices;j++)
        {
            if(dist[j]<min && visited[j]==0)
            {
                min = dist[j]; u = j;
            }
        }
        visited[u] = 1;
        cnt++;
        for(j=1;j<num_vertices;j++)
        {
            if((dist[u]+*((cost + u*num_vertices)+j))<dist[j] && visited[j]==false)
            {
                dist[j] = dist[u] + *((cost + u*num_vertices)+j);
            }
        }
    }
    cout<<endl<<endl<<"Minimum distance from source to destination is: "<<dist[num_vertices-1]<<endl;
    return ;
}
int main(void)
{
    cout<<"Considering directed graphs...."<<endl;
    int num_edges , num_vertices ,i,a,b,weight,j;
    cout<<"Enter number of vertex: "<<endl;
    cin>>num_vertices;
    if(num_vertices<=1)
        return 0;
    cout<<"Enter number of edges: "<<endl;
    cin>>num_edges;

    long cost[num_vertices][num_vertices] ;
    bool visited[num_vertices] = {false};

    for(i=0;i<num_vertices;i++)
    {
        for(j=0;j<num_vertices;j++)
        {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j] = INFINITY;
        }
    }
    for(i=0;i<num_edges;i++)
    {
        cout<<"Enter edge numbers and weight: "<<endl;
        cin>>a>>b>>weight;
        cost[a-1][b-1] = weight;
    }

    cout<<endl<<endl<<"OK we have taken your graph successfully !!"<<endl;
    cout<<"Finding smallest path from the node 1....."<<endl;
    ShortestPathDistance(&cost[0][0],num_vertices,visited);
    return 0;
}
