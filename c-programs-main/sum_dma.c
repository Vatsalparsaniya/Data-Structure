#include<stdio.h>
#include<stdlib.h>

int main(){
	int num,*ptr_num,sum = 0;
	printf("Enter the number you want to add : ");
	scanf("%d",&num);

	for(int i = 0;i<num;++i){
		printf("Enter the number %d : ",i+1);
		scanf("%d",ptr_num+i);
		sum+=*(ptr_num+i);
	}

	printf("Sum : %d\n",sum);

	return(0);
}