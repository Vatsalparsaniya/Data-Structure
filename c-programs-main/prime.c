// various c function to check prime number

#include <stdio.h>
#include <stdbool.h>

bool prime1(int number){
	for(int i = 2;i<number;++i){
		if(number%i==0)
			return false;
	}
	return true;
}

bool prime2(int number){
	for(int i = 2;i<number/2;++i){
		if(number%i==0)
			return false;
	}
	return true;
}



int main(){
	int number,flag;
	printf("Enter the number to check : ");
	scanf("%d",&number);
	flag = prime2(number);
	if(flag)
		printf("%d is a prime number \n");
	else
		printf("%d is not a prime number\n");
	return(0);

}