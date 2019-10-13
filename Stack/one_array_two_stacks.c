// A C program to implement two stacks using a single array

#include <stdio.h>
#define SIZE 10


void pushA();
void pushB();
void popA();
void popB();
int menu();
void display();

int array[SIZE];
int topA = -1;
int topB = SIZE;

int main()
{
    menu();
}

//MENU 
int menu()
{
    int opt,elm;
    printf("\n Menu \n");
    printf("1. Push to Stack 1 \n2. Pop from Stack 1 \n3. Push to Stack 2 \n4. Pop from Stack 2 \n5. Display\n6. Exit\n");
    printf("\nChoose an option: ");
    scanf("%d",&opt);

    if (opt == 1)
    {
        printf("Enter a number: ");
        scanf("%d",&elm);
        pushA(elm);
        menu();
    }
    else if(opt == 2)
    {
        popA();
        menu();
    }
    else if (opt == 3)
    {
        printf("Enter a number: ");
        scanf("%d",&elm);
        pushB(elm);
        menu();
    }
    else if(opt == 4)
    {
        popB();
        menu();
    }

    else if(opt == 5)
    {
        display();
        menu();
    }
    else
    {
        return 0;
    }
}

void pushA(int elm)
{
    if(topA == topB - 1 || topA == SIZE -1 )
    {
        printf("\nstack overflow !\n");
    }
    else
    {
        topA++;
        array[topA] = elm;
        printf("\n%d pushed to stack 1\n",elm);
    }
}

void popA()
{
    int temp;
    if(topA == -1)
    {
        printf("\nstack underflow !\n");
    }
    else
    {
        temp = array[topA];
        array[topA] = 0;
        printf("\n%d popped from stack 1\n",temp);
        topA--;
    }
}

void pushB(int elm)
{
    if(topA == topB - 1 || topB == -1)
    {
        printf("\nstack overflow !\n");
    }
    else
    {
        topB--;
        array[topB] = elm;
        printf("\n%d pushed to stack 2\n",elm);
    }
}

void popB()
{
    int temp;
    if(topB == SIZE)
    {
        printf("\nstack underflow !\n");
    }
    else
    {
        temp = array[topB];
        array[topB] = 0;
        printf("\n%d popped from stack 2\n",temp);
        topB++;
    }
}

void display()
{
    int i;
    printf("\nStack\n");
    for (i=0 ; i < SIZE ; i++)
    {
        printf("%d\n",array[i]);
    }
}