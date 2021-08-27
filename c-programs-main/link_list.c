#include <stdio.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node node;

int print(node*);



int main(){
	node n1,n2,n3,n4;
	node* head;
	n1.data = 12; 
	n2.data = 13; 
	n3.data = 15; 
	n4.data = 19; 
	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;
	print(head);
	return(0);
}

int print(node* head){
	while(head!=NULL){
		printf("%d\n",head->data);
		head = (head->next);
	}
	
	return(0);
}