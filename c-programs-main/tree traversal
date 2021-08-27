#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;

Node* createNode(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void linker(Node* left,Node* papa,Node* right){
	papa->left = left;
	papa->right = right;
}

bool checkFullTree(Node* root){
	if(!root)
		return true;
	if(!(root->left) && !(root->right))
		return true;
	if((root->left) && (root->right))
		return checkFullTree(root->left) && checkFullTree(root->right);
	return false;
}

bool order(Node* root){
	if(!root)
		return false;

	// pre-order
	order(root->left);
	order(root->right);
	printf("%d\n",root->data);

	// in-order
	// order(root->left);
	// order(root->right);
	// printf("%d\n",root->data);

	// post-order
	// order(root->left);
	// order(root->right);
	// printf("%d\n",root->data);

	return true;
}



int main(){
	Node* n1 = createNode(23);
	Node* n2 = createNode(27);
	Node* n3 = createNode(3);
	Node* n4 = createNode(2);
	Node* n5 = createNode(1);
	Node* n6 = createNode(225);
	Node* n7 = createNode(-1);
	Node* n8 = createNode(0);
	Node* n9 = createNode(-8);
	// Node* n10 = createNode(44);
	linker(n2,n1,n3);
	linker(n4,n2,n5);
	linker(n6,n3,n7);
	linker(n8,n4,n9);
	order(n1);
	// if(checkFullTree(n1))
	// 	printf("This is a full tree\n");
	// else
	// 	printf("this is not a full tree\n");
	return(0);
}
