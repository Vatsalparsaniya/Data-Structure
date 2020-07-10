#include<stdio.h>
#include<conio.h>
#define max 5
int top=-1,stack[max];
void pop();
void push(int element);
void display();
int main()
{
	int ch,n,val;
	while(ch!=4)
	{
		printf("Enter the choice \n");
		printf("1. push \n");
		printf("2. pop \n");
		printf("3. display \n");
		printf("4. exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the element to be inserted");
				scanf("%d",&n); 	
				push(n);
				break;
					  
			case 2:pop();
				break;
					   
			case 3:display();
				break;
			case 4:printf("Thank you");
				break;
			default:printf("invalid input");			  
						
		}	
	}
	
		
}
void push(int element)
{
	if(top==max-1)
	{
		printf("overflow");
	}
	else
	{
		top=top+1;
		stack[top]=element;
	}
}
void pop()
{
	int val;
	if(top == -1)
	{
		printf("underflow");
		
	}
	else
	{
		val=stack[top];
		top=top-1;
	}
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d \t",stack[i]);
	}
	printf("\n");
}