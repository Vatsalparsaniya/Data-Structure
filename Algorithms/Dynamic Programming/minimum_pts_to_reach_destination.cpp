// Problem statement, I/O formats clearly explained: https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination/0

#include <bits/stdc++.h>
using namespace std;

int mini=INT_MAX,**arr;

void count(int r,int c,int cr,int cc,int csum,int locmin){
    
    int newsum = csum+arr[cr][cc];
    if(cr==r-1 && cc==c-1)
    mini = min(mini,min(locmin,newsum)>0?1:(1-min(locmin,newsum)));
    
    else if(cr<r-1 && cc<c-1){
        count(r,c,cr+1,cc,csum+arr[cr][cc],min(locmin,csum+arr[cr][cc]));
        count(r,c,cr,cc+1,csum+arr[cr][cc],min(locmin,csum+arr[cr][cc]));
    }
    else if(cr<r-1)
    count(r,c,cr+1,cc,csum+arr[cr][cc],min(locmin,csum+arr[cr][cc]));
    
    else if(cc<c-1)
    count(r,c,cr,cc+1,csum+arr[cr][cc],min(locmin,csum+arr[cr][cc]));
    
}
int main()
 {
	int test,r,c;
	cin>>test;
	while(test--){
	    mini=INT_MAX;
	    cin>>r>>c;
	    arr = (int **)malloc(r * sizeof(int *)); 
         for (int i=0; i<r; i++) 
         arr[i] = (int *)malloc(c * sizeof(int)); 
	    for(int i=0;i<r;i++)
	    for(int j=0;j<c;j++)
	    cin>>arr[i][j];
	    count(r,c,0,0,0,INT_MAX);
	    cout<< mini << endl;
	    
	}
	return 0;
}

