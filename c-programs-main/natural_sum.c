// various function to find sum of first n natural number

#include <stdio.h>

int sum1(int number){
	if(number==1)
		return 1;
	else
		return(sum1(number-1)+number);
}

int sum2(int number){
	return (int)number*(number+1)/2;
}

int sum3(int number){
	int sum = 0;
	for(int i = 1;i<number+1;++i){
		sum+=i;
	}
	return sum;
}

int sum4(int number){
	int sum = 0;
	int counter = 1;
	while(counter!=number+1){
		sum+=counter;
		counter++;
	}
	return sum;
}

int sum5(int number){
	int sum = 0;
	int counter = 1;
	do{
		sum+=counter;
		counter++;
	}
	while(counter!=number+1);

	return sum;
}

int main(){
	int number,sum;
	printf("Enter the number : ");
	scanf("%d",&number);
	sum = sum5(number);
	printf("Sum = %d\n",sum);
	return(0);
}
