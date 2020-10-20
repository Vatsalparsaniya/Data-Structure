/*
    Program to implement Segment Tree in an Array 
    We have an array arr[0 . . . n-1]. 
    We should be able to : 
    1. Find the sum of elements from index l to r where 0 <= l <= r <= n-1
    2. Change value of a specified element of the array to a new value x. 
       We need to do arr[i] = x where 0 <= i <= n-1.
    
    References : http://codeforces.com/blog/entry/18051
*/

#include <bits/stdc++.h> 
using namespace std; 

const int N = 100000; 
int n; 
int tree[2*N]; 

// Construct Tree
void buildTree( int arr[]) { 
	// Insert Leaf Nodes 
	for (int i=0; i<n; i++)	 
		tree[n+i] = arr[i]; 
	
	// Form the tree from their parents
	for (int i = n - 1; i > 0; i--)	 
		tree[i] = tree[i<<1] + tree[i<<1 | 1];	 
} 

// Function to update a tree node 
void updateTreeNode(int p, int value) { 

	// Set value at position p 
	tree[p+n] = value; 
	p = p+n; 
	
	// Move up and update parent nodes
	for (int i=p; i > 1; i >>= 1) 
		tree[i>>1] = tree[i] + tree[i^1]; 
} 


int query(int l, int r) { 
	int sum = 0; 
	
	// Sum on interval [l, r) 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
		if (l&1) // checks whether l is odd or not
			sum += tree[l++]; 
	
		if (r&1) 
			sum += tree[--r]; 
	} 
	
	return sum; 
} 

int main() { 
    int si, se, num, val, index;
    cout << "\nEnter size of array : ";
    cin >> num;
    n = num;
    int a[n];
    cout << "\nEnter elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
	
	// build tree | Tree Stored in Tree[]
	buildTree(a); 
	
    // Sum in range(startIndex, endIndex) index-based
    cout << "\nEnter start index and end index for Query : ";
    cin >> si >> se; 
	cout << query(si, se)<<endl; 
	
    // modify element at 2nd index 
    cout << "\nEnter value and index to modify : ";
    cin >> val >> index;
	updateTreeNode(val, index); 
	
    // Sum in range(startIndex, endIndex) index-based
    cout << "\nEnter start index and end index for Query after update: ";
    cin >> si >> se; 
	cout << query(si, se)<<endl; 

	return 0; 
} 
