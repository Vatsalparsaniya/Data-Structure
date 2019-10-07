#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int front=-1,rear=-1,q[MAXSIZE];
void insert(int a){
   if(front==(rear+1)%MAXSIZE) printf("Error!!\nQueue is full!!!\n");
   else{
        if(front==-1) front=0;
        rear =(rear+1)%MAXSIZE;
        q[rear]=a;
        }
}

void delete(){
    if(front==rear){
        printf("Error!! \n Underflow condition\n Queue is empty\n");
    }
    else{
        q[front]=0;
        front=(front+1)%MAXSIZE;
        printf("element successfully delete\n");
        }
}

void display(){
    int i=0;
    for(i=0;i<MAXSIZE;i++){
        printf(" %d  |",q[i]);
    }
    printf("\n");
}

int main(){
    int choise=0,inse;
     printf(" 1) insert element \n 2) delete element \n 3) display queue  \n 4) exit\n");
    while(choise != 4){
    printf(" enter your choice :");
    scanf("%d",&choise);
    switch(choise)
    {
    case 1:
        printf("enter a number which you want  to add in queue:");
        scanf("%d",&inse);
        insert(inse);
        break;
    case 2:
        printf("you chose delete option\n");
        delete();
        break;
    case 3:
        printf("you chose display option\n");
        display();
        break;
    case 4:
        printf("\ni hope u enjoy this prg\n");
        break;
    }
}
return 0;

}


