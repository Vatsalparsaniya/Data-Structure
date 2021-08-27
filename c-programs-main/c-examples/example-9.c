// C Program to Check Whether a Number is Even or Odd

#include <stdio.h>

int main(){
	int number;
	printf("Enter the number : ");
	scanf("%d",&number);
	if(number%2==0)
		printf("%d is a even number\n",number);
	else
		printf("%d is not a even number\n",number);
	return(0);
}