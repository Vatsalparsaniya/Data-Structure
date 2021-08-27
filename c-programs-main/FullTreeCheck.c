#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *left,*right;
}Node;

Node* createNode(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void linker(Node* left,Node* parent,Node* right){
	parent->left = left;
	parent->right = right;
}

bool preOrder(Node* root){
	if(!root)
		return false;
	printf("%d\n",root->data);
	preOrder(root->left);
	preOrder(root->right);
	return true;
}

bool inOrder(Node* root){
	if(!root)
		return false;
	printf("%d\n",root->data);
	inOrder(root->left);
	inOrder(root->right);
	return true;
}

bool postOrder(Node* root){
	if(!root)
		return false;
	printf("%d\n",root->data);
	postOrder(root->left);
	postOrder(root->right);
	return true;
}

bool checkFullTree(Node* root){
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right==NULL)
		return true;
	if(root->left && root->right)
		return checkFullTree(root->left) && checkFullTree(root->right);
	return false;
}

int main(){
	Node* n1 = createNode(12);
	Node* n2 = createNode(11);
	Node* n3 = createNode(14);
	Node* n4 = createNode(18);
	Node* n5 = createNode(120);
	Node* n6 = createNode(121);
	Node* n7 = createNode(124);
	Node* n8 = createNode(22);
	Node* n9 = createNode(28);
	linker(n2,n1,n3);
	linker(n4,n2,n5);
	linker(n6,n3,n7);
	linker(n9,n6,n8);
	if(checkFullTree(n1))
		printf("It is a full tree\n");
	else
		printf("Not a full tree\n");
	return(0);
}
