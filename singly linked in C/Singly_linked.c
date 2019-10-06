#include<stdio.h>  
#include<stdlib.h>  
void randominsert(int);  
void create(int);  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void main ()  
{  
    int choice,item,loc;  
    do   
    {  
        printf("nEnter the item which you want to insert?n");  
        scanf("%d",&item);  
        if(head == NULL)  
        {  
            create(item);  
        }  
        else  
        {  
            randominsert(item);  
        }  
        printf("nPress 0 to insert more ?n");  
        scanf("%d",&choice);  
    }while(choice == 0);  
}  
void create(int item)  
{  

        struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
        if(ptr == NULL)  
        {  
            printf("nOVERFLOWn");  
        }  
        else  
        {  
            ptr->data = item;  
            ptr->next = head;  
            head = ptr;  
            printf("nNode insertedn");  
        }  
}  
void randominsert(int item)  
    {  
        struct node *ptr = (struct node *) malloc (sizeof(struct node));  
        struct node *temp;  
        int i,loc;  
        if(ptr == NULL)  
        {  
            printf("nOVERFLOW");  
        }  
        else  
        {  

            printf("Enter the location");  
            scanf("%d",&loc);             
            ptr->data = item;  
            temp=head;  
            for(i=0;i<loc;i++)  
            {  
                temp = temp->next;  
                if(temp == NULL)  
                {  
                    printf("ncan't insertn");  
                    return;  
                }  

            }  
            ptr ->next = temp ->next;   
            temp ->next = ptr;   
            printf("nNode inserted");  
        }  

    }
