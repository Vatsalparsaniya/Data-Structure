// various function/ways to  to Swap Two Numbers

#include <stdio.h>

void swap1(){
	int a,b,c;
	printf("Enter the numbers(use ',') : ");
	scanf("%d,%d",&a,&b);
	c = a;
	a = b;
	b = c;
	printf("a = %d\nb = %d\n",a,b);
}

void swap2(){
	int a,b;
	printf("Enter the numbers(use ',') : ");
	scanf("%d,%d",&a,&b);
	a = a+b;
	b = a-b;
	a = a-b;
	printf("a = %d\nb = %d\n",a,b);
}

void swap3(){
	int a,b;
	printf("Enter the numbers(use ',') : ");
	scanf("%d,%d",&a,&b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a = %d\nb = %d\n",a,b);
}

int main(){
	swap1();
	swap2();
	swap3();
	return(0);
}