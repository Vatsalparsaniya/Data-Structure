#include <stdio.h>
#include <stdlib.h>
int top=-1;

void push(int s[],int n,int x){
    if(top<n-1){
        s[++top]=x;
    }
    else
        printf("srtack is full\n");
}

int pop(int s[],int n){
    if(top==-1) {
            printf("stack is empty\n");
            return 0;
    }
    else return s[top--];
}

void display(int s[]){
    int n;
    n=top;
    int i;
for(i=n;i>=0;i--){
printf("\n|  %4d      |",s[i]);
    }
    printf("\n--------------\n");
}


int main(){
int n,x;
printf("enter size of stack : ");
scanf("%d",&n);

int s[n];
int choise;
printf("\n\n ------------------------------------------------------\n");
printf("choise what do u whant\n");
printf("1. push \n2. pop \n3. disply \n4. exit\n");
printf("------------------------------------------------------\n");

pick :

printf("enter your choise : ");
scanf("%d",&choise);

switch(choise){
case 1:
    printf("enter number you want to add in stack :");
    scanf("%d",&x);
    push(s,n,x);

break;

case 2:
    printf("you poped : %d\n", pop(s,n));
break;

case 3:
    display(s);
break;

case 4:
    exit(0);
}

goto pick;
return 0;
}
