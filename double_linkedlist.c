#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void main()
{
	struct node *head=NULL,*last,*temp,*newNode;
	int n ,choice,data;
	 head=NULL;
	 last=NULL;

	 printf("enter the size of linked list\n");
	 scanf("%d",&n);
	 if(n>=1)
	 {
	 	head =(struct node*)malloc(sizeof(struct node));
	 	if(head != NULL)
	 	{
	 		printf("enter data of node 1 : ");
	 		scanf("%d",&data);
	 		head->data=data;
	 		head->prev=NULL;
	 		head->next=NULL;
	 		last=head;

	 		for (int i = 2; i <=n; i++)

	 		{
				newNode = (struct node*)malloc(sizeof(struct node));
				if(newNode!=NULL)
				{
					printf("Enter data of node %d :",i );
					scanf("%d",&data);

					newNode->data = data;
					newNode->prev = last;
					newNode->next = NULL;

					last->next = newNode;
					last = newNode;
				} 			
	 		}
	 	}
	 }
	 temp=head;
	 while(temp!=NULL)
	 {
	 	printf("%d\n",temp->data );
	 	temp =temp->next;
	 }

}