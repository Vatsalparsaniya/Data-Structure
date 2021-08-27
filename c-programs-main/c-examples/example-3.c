// C Program to Add Two Integers

#include <stdio.h>

int main(){
	int num1,num2,sum;
	printf("Enter the numbers : ");
	scanf("%d,%d",&num1,&num2);
	sum = num1+num2;
	printf("%d + %d = %d\n",num1,num2,sum);
	return(0);
}