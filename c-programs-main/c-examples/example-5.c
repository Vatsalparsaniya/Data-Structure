// C Program to Find ASCII Value of a Character

#include <stdio.h>

int main(){
	char symbol;
	printf("Enter the symbol : ");
	scanf("%c",&symbol);
	printf("ASCII value of %c is %d\n",symbol,symbol);
	return(0);
}