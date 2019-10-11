#include <stdio.h>
int main()
{
	int size;
	printf("Enter the number of creature :");
	scanf("%d",&size);
	int arr[size],even[size],evenlist=0,evensum=0,odd[size],oddlist=0,oddsum=0,key,j,smallest;
	printf("Enter the power and list:");
	for(int m=0;m<size;m++)
	{
		scanf("%d",&arr[m]);
	}
	printf("The power of zombie is %d\n",arr[1]);
	printf("The power of vampire is %d\n",arr[2]);

	for(int i=0;i<size;i++)
	{
		if(arr[i]%2==0)
		{
			even[evenlist]=arr[i];
			evenlist++;
			evensum=evensum+arr[i];
		}
		else
		{
			odd[oddlist]=arr[i];
			oddlist++;
			oddsum=oddsum+arr[i];
		}
	}
	for(int i=1;i<=oddlist;i++)
	{
		key=odd[i];
		j=i-1;
		while(j>=0 && odd[j]>key)
		{
			odd[j+1]=odd[j];
			j--;
			odd[j+1]=key;
		}
	}
	for(int i=1;i<=sevenlist;i++)
	{
		key=even[i];
		j=i-1;
		while(j>=0 && even[j]>key)
		{
			even[j+1]=even[j];
			j--;
			even[j+1]=key;
		}
	}
	for(int k=0;k<evenlist;k++)
		printf("%d\t",even[k]);
	printf("%d\n",evensum );
	printf("\n");
	for(int k=0;k<oddlist;k++)
		printf("%d\t",odd[k]);
	printf("%d\n",oddsum );
return 0;
}
