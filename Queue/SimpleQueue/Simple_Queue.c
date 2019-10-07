#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int front=-1,rear=-1,q[MAXSIZE];
void insert(int a){
    if(rear>=MAXSIZE){
        printf("sorry!! \n queue is full \n");
    }
    else{
        if(front==-1) front=0;
        rear++;
        q[rear]=a;
        printf("element %d is successfully added\n",a);
        }
}

void delete(){
    if(front<0){
        printf("Error!! \n Underflow condition\n");
    }
    else if(front==rear){
        q[front]=0;
        front=-1;
        rear=-1;

        printf("element successfully delete\n");
    }
    else{
        q[front]=0;
        front++;
        printf("element successfully delete\n");
        }


}

void display(){
    int i=0;
    for(i=0;i<=MAXSIZE;i++){
        printf(" %d  |",q[i]);
    }
    printf("\n");
}

int main(){
    int choise=0,inse;
    printf(" 1) insert element \n 2) delete element \n 3) display queue  \n 4) exit\n ");
    while(choise != 4){
    printf("enter your choice : ");
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
        printf("\nI hope u enjoy this program \n");
        break;
    }
}
return 0;

}


