#include<stdio.h>
#include<conio.h>

typedef struct list
{
  int info;
  struct list *next;
}list;

list *start,*newnode,*p,*q,*end,*beg,*pos1;
int item;
void traverse()
{
	q=start;
   while(q!=NULL)
   {
     printf("%d\t",q->info);
     q=q->next;
   }
}
 void insert_end()
 {
   list *ptr,*end;
   int item;
      newnode=(list*)malloc(sizeof(list));
      printf("\nenter element to insert at end");
      scanf("%d",&item);
      newnode->info=item;
      newnode->next=NULL;
   if(start==NULL)
     start=newnode;
   else
     {
       ptr=start;
       while(ptr!=NULL)
	 {
	   end=ptr;
	   ptr=ptr->next;
	 }
	 end->next=newnode;
     }
   traverse();
 }
void insert_beg()
 {
 printf("\nenter number");
 scanf("%d",&item);
	  newnode=(list*)malloc(sizeof(list));
	  newnode->next=start;
	  start=newnode;
	 newnode->info=item;
	 traverse();
 }
void delte_beg()
{
 list *ptr;
  if (start==NULL)
     printf("\nunderflow");
    else
    {
     ptr=start;
     start=ptr->next;
     free(ptr);
     traverse();
    }
  }
void delte_end()
{
  list *ptr,*pos;
  if(start==NULL)
  printf("\nunderflow");
  else
  {
   ptr=start;
   while(ptr->next!=NULL)
   {
    pos=ptr;
    ptr=ptr->next;
   }
   pos->next=NULL;
     free(ptr);
     traverse();
    }
  }
void insert_mid()
 {
  int pos,i;
  list *ptr;
  newnode=(list*)malloc(sizeof(list));
  printf("\nenter item");
  scanf("%d",&item);
  newnode->info=item;
  printf("enter position");
  scanf("%d",&pos);
   ptr=start;
   if(start==NULL)
     start=newnode;
     else
      {
       for(i=1;i<pos;i++)
	{
	  pos1=ptr;
	  ptr=ptr->next;
	  if(ptr==NULL)
	  {
	   pos1->next=newnode;
	   newnode->next=ptr;
	   printf("your desierd posi.is not available");

	 }
	 }
	 pos1->next=newnode;
	   newnode->next=ptr;

	   traverse();
	   }

}
void delet_mid()
{
  int pos,i;
  list *ptr,*p1,*q1;
  printf("enter position ");
  scanf("%d",&pos);
  ptr=start;
if(pos=='1')
{
  p1=ptr;
  ptr=ptr->next;
  start=ptr;
}
for(i=1;i<pos;i++)
   {
    p1=ptr;
    ptr=ptr->next;
    q1=ptr->next;
   }
  p1->next=q1;
  free(ptr);
 traverse();
}
void main()
{
 int item,ch;
  clrscr();
  start=NULL;
       printf("enter number");
       scanf("%d",&item);
	  while(item!=0)
	    {
	      newnode=(list*)malloc(sizeof(list));
	      newnode->info=item;
	      newnode->next=NULL;
		if(start==NULL)
		  {
		       start=newnode;
		       p=newnode;
		  }
		     else
			 {
			     p->next=newnode;
			   p=newnode;
			 }
		     printf("enter item\n");
		     scanf("%d",&item);
	     }
   traverse();
   do
   {
     printf("enter 1 for insert begging\n");
     printf("enter 2 for insert end\n");
     printf("enter 3 for insert at mid");
     printf("enter 4 for delte at begging\n");
     printf("enter 5 for delte at end\n");
    printf("enter 6 for delet at mid\n");
    printf("ENter 7 for exit");
    printf("Enter the choice\n");
    scanf("%d",&ch);
     switch(ch)
       {
	 case 1: insert_beg();
		  break;
	 case 2: insert_end();
		  break;
	case 3:insert_mid();
		break;
	case 4:delte_beg();
		break;
	case 5:delte_end();
		break;
	case 6:delet_mid();
	       break;
       }
    }while(ch!=7);
 getch();
}
