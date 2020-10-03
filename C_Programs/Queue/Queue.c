/*Author: Jithin Jose
 *GitHub: defaultRectr0
 *stack operations using arrays
*/
#include <stdio.h>
#include <stdlib.h>
void add();
void dlt();
void display();
int queue_array[100];
int rear = - 1;
int front = - 1;
int n;
void add()
{
    int add_item;
    if (rear== n-1)
    printf("Queue Overflow\n");
    else
    {
        if (front ==-1)
        front = 0;
        printf("Enter the element to be Added\n");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
void dlt()
{
    if (front==-1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element removed\n");
        front = front + 1;
    }
} 
void display()
{
    int i;
    if (front==-1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
        {
            printf("\t%d ", queue_array[i]);
        }
        printf("\n");
    }
}
void main()
{
   int choice;
   printf("Enter the size of the array\n");
   scanf("%d",&n);
 do
 {
    {
        printf("\n1.To Enter element \n");
        printf("2.To remove element\n");
        printf("3.Display \n");
        printf("4.Quit \n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            add();
            break;
            case 2:
            dlt();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Wrong choice \n");
        } 
    } 
} 
while(choice!=4);
}

