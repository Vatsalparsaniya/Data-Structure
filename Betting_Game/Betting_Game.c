#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,b,r,*a;

void start(){
    srand(time(0));

    a = (int*)malloc(3*sizeof(int));
    *a=rand()%3;
    *(a+1)= rand()%3;
    *(a+2)= rand()%3;

    if(n>0){

        printf("you have currently $%d \n",n);
        printf("enter the bet amount $");
        scanf("%d",&b);
        if(b<=n){
        printf("find the place of queen[chose 1,2,3] : ");
        scanf("%d",&r);
        if(*a==(r-1) ){
            printf("congratulations you win!\n");
            n=n-b+(3*b);
            printf("now you have $%d\n",n);
            printf("______________________________\n");
            }
        else{
            printf("Better luck Next time\n");
            n=n-b;
            printf("now you have $%d \n",n);
            printf("______________________________\n");
        }
        }else{
            printf("you have only $%d and you Bet $%d \n",n,b);

        }

    }
    else{
            printf("you are not eligible to play game \n you ave no money\n");
        }
        free(a);

}
int main(){



printf("______________________________\n");
printf("      BETTING GAME\n");
printf("______________________________\n");
printf("  *****    *****    *****\n");
printf("  *   *    *   *    *   *\n");
printf("  * j *    * Q *    * K *\n");
printf("  *   *    *   *    *   *\n");
printf("  *****    *****    *****\n");
printf("______________________________\n");
printf("rules : \n");
printf("1) you have to chose between 1 to 3 \n");
printf("2) you are allow to play till you have $0 \n");
printf("3) if you will win then you will get 3*(BET AMOUNT)\n\n\n");
printf("how many amount you have $");
scanf("%d",&n);
int f;
f=n;

    printf("\n\n*******************************************\n");
    printf("                GAME START    \n");
    printf("*******************************************\n\n");
//printf("you want to play game(y/n):");
//char m;
//scanf("%c",&m);
while(n!=0){
start();
//printf("you want to play game again!(y/n):");
//scanf("%c",&m);
}
printf("\n\n\n\nyou come with $%d\n",f);
printf("now you have $%d\n\n\n",n);
printf("thank you for play!\n\n\n");
return 0;

}


