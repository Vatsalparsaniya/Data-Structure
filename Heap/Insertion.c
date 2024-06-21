#include<stdio.h>
void insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];
    while(temp>A[i/2] && i>1)
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void createHeap()
{
    int A[]={0,10,20,30,40,50,25};
    int i;
    for(int i=2;i<=6;i++)
    {
        insert(A,i);
    }
}
int main()
{
    createHeap();
    return 0;
}