#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 20


int front = 0,rear= -1,top=-1;
struct Node{
    char car[20];
    struct Node *ptr;
    int n;
};

struct stack1{
	char soldCar[20];
};

struct stack1 sold[20];

struct Node *insCar(struct Node *head){
	struct Node *NewNode;
	struct Node *temp;
	temp = head;

	NewNode = (struct Node*)malloc(sizeof(struct Node));
		if(NewNode == NULL){
		printf("SORRY MALLOC FAILD\n");
	}

	printf("enter the car brand name :");
	scanf("%s",(NewNode->car));

	printf("How many %s car u have :",NewNode->car);
	scanf("%d",&(NewNode->n));
	printf("\n");

	NewNode->ptr = NULL;
	if(temp == NULL){
	head = NewNode;
	}else{
	while(temp->ptr != NULL)
	temp = temp->ptr;
	temp->ptr = NewNode;
	}

	return head;

}
void push(char c[]){
    strcpy(sold[++top].soldCar,c);
}

void Buy(struct Node *head){
        printf("\n");
        printf("costumer %d :\n",top+2);
        printf("which car u Want to Buy :");
        char costumerCar[20];
        scanf("%s",costumerCar);
        struct Node *temp;
        temp = head;
        while(strcmp(temp->car,costumerCar)){
                temp = temp->ptr;
                if(temp == NULL){
                    break;
                }
                }
        if(temp == NULL){
                printf("that car Brand is not available\n");
                Buy(head);

        }else{
            if(temp->n == 0){
                printf("Sorry Out of stock\n");
                Buy(head);
            }
            else{
                (temp->n)--;
                push(costumerCar);

            }
            }

}


void display(struct Node *head){
    struct Node *temp;
    temp = head;
    printf("\n\n");

    while(temp != NULL){
        printf("car : %s | amount : %d\n", temp->car,temp->n);
        temp = temp->ptr;
    }
    }
int main(){
    struct Node *Head;
    Head = NULL;
	printf("**********************************\n\tWelcome to car shop\n**********************************");
	int b,i;
	printf("\nHow many car Brand u Want to add :");
	scanf("%d",&b);
	printf("\n");
	for(i=0;i<b;i++){
		Head = insCar(Head);
	}
	printf("\n");
	printf("How many costumers :");
	int c;
	scanf("%d",&c);
	printf("\n");
    for(i=0;i<c;i++){
		Buy(Head);
	}

	display(Head);
	printf("\n\nlast sold car is %s\n\n",sold[top].soldCar);
}
