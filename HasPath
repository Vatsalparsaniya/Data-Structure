/*
                                          code in c++
    inputs an graph having n vertices and e edges, then takes a starting and ending vertex and tells if there exists a path between the vertices
*/

#include<bits/stdc++.h>

using namespace std;

bool printBFS( int **edges, int n, int sv, int f)
{
    std::queue<int > pv;
    
     bool* visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    
    pv.push(sv);
    visited[sv]=true;
    while(!pv.empty())
    {
        int curv=pv.front();
        if(curv==f) {cout<<"true"; return true;}
        pv.pop();
        //cout<<curv<<" ";
        for(int i=0; i<n; i++)
        {
            if(i==curv){continue;} 
            if(edges[curv][i]==1 && !visited[i]){
                pv.push(i);
                visited[i]=true;
            }
        } 
    }
    delete []visited;
    cout<<"false";
  return false;
    
}

int main()
{
    int n, e;
    cin>>n>>e;
    int** edges= new int *[n];
    for(int i=0; i<n; i++)
    {
        edges[i]=new int [n];
        for(int j=0; j<n; j++)
        {
            edges[i][j]=0;
        }
    }
    
    for(int i=0; i<e; i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
    int s, end;
    cin>>s>>end;
    
    printBFS(edges, n,  s, end);
   
    //delte arrays
    for(int i=0; i<n; i++)
    {
        delete []edges[i];
    }
    delete []edges;
    return 0;
}
