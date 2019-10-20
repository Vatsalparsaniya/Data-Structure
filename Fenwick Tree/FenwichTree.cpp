//Fenwick Tree as known as Binary Indexed Tree(BIT)

#include<iostream>
using namespace std;

int next(int i)
{
    return (i + (i & (-i)));
}

int par(int i)
{
    return (i - (i & (-i)));
}

int getSum(int * BIT, int n,int i)
{
    int sum = 0, j = i+1;
    do
    {
        sum += BIT[j];
        j = par(j);
    } while (j>0);
    return sum;
}

void updateBIT(int * BIT, int n, int i, int val)
{
    i++;
    do{
        BIT[i] += val;
        i = next(i);
    } while(i<=n);
    return ;
}

int * createBIT(int * arr, int n)
{
    int * BIT = new int[n+1]{0};
    for(int i=0 ; i<n ; i++)
        updateBIT(BIT, n+1, i, arr[i]);
    return BIT;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];

    int * BIT = createBIT(arr, n);

    for(int i=0 ; i<=n ; i++)
        cout<<BIT[i]<<" ";
    cout<<endl;
    
    cout<<getSum(BIT, n+1, 3);
    return 0;
}