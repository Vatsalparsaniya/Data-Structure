#include<stdio.h>
#include<conio.h>
#include<process.h>

int n,top=-1;

void display(int stack[100],int n)
{
int i;
	printf("\n");
	for(i=top;i>=0;i--)
	{
		printf("\t%d\n",stack[i]);
	}
	printf("\n");
}

void push(int stack[100],int n)
{
int item;
	if(top>=n-1)
		printf("Overflow\n");
	else
	{	printf("Enter the element : ");
		scanf("%d",&item);
		top=top+1;
		stack[top]=item;
		display(stack,n);
	}
}

void pop(int stack[100],int n)
{
int item;
	if(top<=-1)
		printf("Underflow\n");
	else
	{
		item=stack[top];
		top=top-1;
		printf("\n%d deleted\n",item);
	}
	display(stack,n);
}

void main()
{
int stack[100];
char ch,ans='y';
clrscr();
	printf("Enter the size of the stack : ");
	scanf("%d",&n);
	do{
	printf("\nEnter your choice(1-4)\n\n1.Push\n\n2.Pop\n\n3.Traverse\n\n4.Exit\n\t==>");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
			push(stack,n);
		break;
		case 2:
			pop(stack,n);
		break;
		case 3:
			display(stack,n);
		break;
		case 4:
			exit(0);
		break;
		default:
		printf("Wrong input\n");
	}

	printf("Do you want to operate again...? ");
	scanf(" %c",&ans);
	}while(ans=='Y'||ans=='y');
getch();
}