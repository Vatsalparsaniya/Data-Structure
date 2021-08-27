#include <stdio.h>
#include <stdbool.h>

#define MIN 1

bool checkLeap(int year){
	if(year%400==0)
		return true;
	else if(year%100==0)
		return false;
	else if(year%4==0)
		return true;
	else
		return false;
}

int main(){
	int year;
	bool flag;
	printf("Enter the year to check : ");
	scanf("%d",&year);
	if(year<MIN)
		printf("%d is not a valid year\n");
	else{
		flag = checkLeap(year);
		if(flag)
			printf("%d is a leap year\n",year);
		else
			printf("%d is not a leap year\n",year);
	}

	return(0);
}
