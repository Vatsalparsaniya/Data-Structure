#include <stdio.h>

#define LENGTH 10

int top = -1;
int stack[LENGTH];

void push_stack(int item){
	if(top==LENGTH){
		printf("Stack is full\n\a");
	}
	else{
		top+=1;
		stack[top] = item;
	}
}

int pop(){
	if(top==-1){
		printf("Stack is Empty\n\a");
	}
	else{
		top-=1;
		return stack[top+1];
	}
}

void isEmpty(){
	if(top==-1)
		printf("Yes!!\n\a");
	else
		printf("No!!\n\a");
}

void isFull(){
	if(top==LENGTH)
		printf("Yes!!\n\a");
	else
		printf("No!!\n\a");
}

int displayStack(){
	if(top==-1){
		printf("Empty Stack!!\n\a");
		return(0);
	}
	printf("%d  <----head\n",stack[top]);
	for(int i = top-1;i>-1;--i){
		printf("%d\n",stack[i]);
	}
}


int main(){
	push_stack(12);
	push_stack(23);
	push_stack(67);
	push_stack(1128);
	push_stack(444);
	pop();
	displayStack();
	return(0);
}