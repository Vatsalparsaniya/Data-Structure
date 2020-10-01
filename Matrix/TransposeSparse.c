#include<stdio.h>
 
#define MAX 20
 
void printsparse(int[][3]);
void readsparse(int[][3]);
void transpose(int[][3],int[][3]);
 
int main()
{
	int b1[MAX][3],b2[MAX][3],m,n;
	printf("Enter the size of matrix (rows,columns):");
	
	scanf("%d%d",&m,&n);
	b1[0][0]=m;
	b1[0][1]=n;
	
	readsparse(b1);
	transpose(b1,b2);
	printsparse(b2);
}
 
void readsparse(int b[MAX][3])
{
	int i,t;
	printf("\nEnter no. of non-zero elements:");
	scanf("%d",&t);
	b[0][2]=t;
	
	for(i=1;i<=t;i++)
	{
		printf("\nEnter the next triple(row,column,value):");
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
	}
}
 
void printsparse(int b[MAX][3])
{
	int i,n;
	n=b[0][2];	//no of 3-triples
	
	printf("\nAfter Transpose:\n");
	
	printf("\nrow\t\tcolumn\t\tvalue\n");
	for(i=0;i<=n;i++)
		printf("%d\t\t%d\t\t%d\n",b[i][0],b[i][1],b[i][2]);
}
 
void transpose(int b1[][3],int b2[][3])
{
	int i,j,k,n;
	b2[0][0]=b1[0][1];
	b2[0][1]=b1[0][0];
	b2[0][2]=b1[0][2];
	
	k=1;
	n=b1[0][2];
	
	for(i=0;i<b1[0][1];i++)
		for(j=1;j<=n;j++)
			//if a column number of current triple==i then insert the current triple in b2
			if(i==b1[j][1])
			{
				b2[k][0]=i;
				b2[k][1]=b1[j][0];
				b2[k][2]=b1[j][2];
				k++;
			}
}
