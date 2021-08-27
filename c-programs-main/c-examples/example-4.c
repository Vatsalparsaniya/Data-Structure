// C Program to Multiply Two Floating-Point Numbers

#include <stdio.h>

int main(){
	float num1,num2,product;
	printf("Enter the numbers(use ',') : ");
	scanf("%f,%f",&num1,&num2);
	product = num1*num2;
	printf("%.2f x %.2f = %.2f\n",num1,num2,product);
	return(0);
}