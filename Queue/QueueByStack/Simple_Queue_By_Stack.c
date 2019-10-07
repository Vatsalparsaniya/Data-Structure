#include <stdio.h>
#include <stdlib.h>
#define max 10
int top1=-1,top2=-1,s1[max],s2[max];
void insert(int p){
    if(top1==max)
        printf("queue is full");
    else{
        top1++;
        s1[top1] = p;
    }
}
void push2(int p){
if(top2==max)
        printf("queue is full");
    else{
        top2++;
        s2[top2] = p;
    }
}
int pop1(){
    int r;
    r=s1[top1];
    top1--;
    return r;

}
void delete1(){
    int i;
    if(top2==-1 && top1==-1){
        printf("queue is empty");
        }
    else if(top2==-1){
        for(i=top1;i>=0;i--){
            push2(pop1());
        }

        printf("Deleted iteam is %d\n",s2[top2--]);
    }
    else{
        printf("Deleted iteam is %d\n",s2[top2--]);
    }
}
void display(){
    int i;
    if(top1==-1 && top2==-1) printf("queue is empty\n");
    for(i=top2;i>=0;i--){
        printf("%d | ",s2[i]);
    }
    for(i=0;i<=top1;i++){
        printf("%d | ",s1[i]);
    }
    printf("\n");

}


int main()
{
    printf(" 1-insert \n 2-delete \n 3-display\n 4-exit\n");
    int ins,c=0;
    while(c!=4){
    printf("enter your choise : ");
    scanf("%d",&c);

    switch(c){
        case 1:
        printf("enter element: ");
        scanf("%d",&ins);
        insert(ins);
    break;
    case 2: delete1();
    break;
    case 3: display();

    break;
     default:	exit(0);
    break;
            }
                }
                return 0;
}


