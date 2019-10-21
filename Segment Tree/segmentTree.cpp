//Segment tree for RMQ(Range Minimum Query)

#include<bits/stdc++.h>
#define ll long long
#define fastIO ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;


//Segment Tree building in O(n)
void built_sg(vector<int> &v, vector<int> &sg, int l, int r, int i)
{
    if(l == r)
        sg[i] = v[l];
    else 
    {
        built_sg(v, sg, l, (l+r)/2, 2*i);
        built_sg(v, sg, (l+r)/2+1, r, 2*i+1);
        sg[i] = min(sg[2*i], sg[2*i+1]);
    }
    return;
}

//Update segment tree in O(log n)
void update_sg(vector<int> &v, vector<int> &sg, int l, int r, int i, int pos, int val)
{
    if(l == r)
        sg[i] = v[pos] = val;
    else
    {
        if(pos < (l+r)/2)
            update_sg(v, sg, l, (l+r)/2 , 2*i, pos, val);
        else     
            update_sg(v, sg, (l+r)/2+1, r, 2*i+1, pos, val);
        sg[i] = min(sg[2*i], sg[2*i+1]);
    }
    return ;
}

//Get answer for query in O(log n)
int query_sg(vector<int> &sg, int l, int r, int x, int y, int i)
{
    if(x > y)
        return 0;
    if(l==x && r==y)
        return sg[i];
    else 
    {
        int mid = (l+r)/2;
        return min(query_sg(sg, l, mid, x, min(mid, y), 2*i), query_sg(sg, mid+1, r, max(mid+1, x), y, 2*i+1));
    }
}

int main()
{
    fastIO;
    int n; //Size of array.
    cin>>n; 
    vector<int> v(n), sg(4*n, -1); //Storing segment tree in an array. An array of size n will always has less than 4n nodes in its segment tree.
    for(int i=0 ; i<n ; i++)
        cin>>v[i];
    
    built_sg(v, sg, 0, n-1, 1);

    int q, l, r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query_sg(sg, 0, n-1, l, r, 1)<<" ";
    }
    
    return 0;
}

