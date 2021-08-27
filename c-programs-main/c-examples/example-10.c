// complex number 

#include <stdio.h>

typedef struct {
	double real;
	double imag;
}complex;

complex add(complex a,complex b){
	complex c;
	c.real = a.real+b.real;
	c.imag = a.imag+b.imag;
	return c;
}

void print(complex a){
	printf("%.2lf + i%.2lf\n",a.real,a.imag);
}

void input(complex *ptr){
	printf("Enter the number(use ',') : ");
	scanf("%lf,%lf",&ptr->real,&ptr->imag);
}

int main(){
	complex num1,num2;
	input(&num1);
	input(&num2);
	complex sum =  add(num1,num2);
	print(sum);
	return(0);
}