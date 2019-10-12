#include<stdio.h>
//Function Declaration for factorial
fact(int n){
              int result;
              if (n == 0){
                            result = 1;
                         }
              else{
                            result = n*fact(n-1); // function calling itself
                  }
              return result;
            }

int main(){
            int res;
            int n;
            printf("enter the value of n : ");
            scanf("%d",&n);
            res = fact(n);
            printf("%d",res);
          }