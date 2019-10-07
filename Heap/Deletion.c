#include<stdio.h>
void swap(int x,int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
void delete(int A[],int n)
{
    int x,i,j;
    x=A[n];
    A[1]=A[n];
    i=1,j=2*i;
    while(j<n-1)
    {
        if(A[j+1]>A[j])
        {
            j=j+1;
        }
        if(A[i]<A[j])
        {
            swap(A[i],A[j]);
            i=j;
            j=2*i;
        }
        else
        {
            break;
        }
        A[n]=x;
    }
}
int main()
{
    int A[]={0,10,20,30,40,50,25};
    delete(A,6);
    return 0;
}