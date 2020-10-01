//GCD
#include<stdio.h> 
int GCD(int,int);
void main()
{    
    int p,q,result;
    printf("Enter two numbers GCD: \n");    
    scanf("%d%d",&p,&q);    
    result=GCD(p,q);
    printf("The  GCD %d",result); 
}
int GCD(int m,int n)
{    
	if(n>m)        
		GCD(n,m);    
	else if(n==0)        
		return m;    
	else        
		GCD(n,m%n); 
} 
