#include<stdio.h>

int get_max(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
        if(max<arr[i])
            max=arr[i];
    return max;
}

void copy_sort(int arr[],int n,int s_arr[],int m)
{
    int temp[m+1];

    for(int i=0;i<m+1;i++)
        temp[i]=0;

    for(int i=0;i<n;i++)
        temp[arr[i]]++;
    for(int i=1;i<m+1;i++)
        temp[i]+=temp[i-1];

    for(int i=n-1;i>=0;i--)
    {
        s_arr[temp[arr[i]] - 1]=arr[i];
        temp[arr[i]]--;
    }
}

int main()
{
    int n,arr[100],s_arr[100],m;

    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    m=get_max(arr,n);
    copy_sort(arr, n, s_arr,m);

    printf("Sorted array: ");
    for(int i=0;i<n;i++)
        printf("%d ",s_arr[i]);

    printf("\n");
}
