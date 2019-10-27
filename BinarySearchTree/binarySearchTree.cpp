// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

//#include "stdlib.h"
//#include "stdafx.h"
#include <iostream>

using namespace std;


class Node {

private:
	int data;
	Node* llink;
	Node* rlink;
	Node* parent;

public:
	Node(int d) {
		data = d;
		llink = NULL;
		rlink = NULL;
		parent = NULL;
	}

//parent
	void setParent(Node* p) {
		parent = p;
	}

	Node* getParent() {
		return parent;
	}
//data
	void setData(int d) {
		data = d;
	}

	int getData() {
		return data;
	}

//llink
	void setLlink(Node* l) {
		llink = l;
	}

	Node* getLlink() {
		return llink;
	}

//rlink
	void setRlink(Node* r) {
		rlink = r;
	}

	Node* getRlink() {
		return rlink;
	}
};

class Tree {
	Node* root;

public:
	Tree() {
		root = NULL;
	}

//traverse whole tree with preorder postorder and inorder traversing
	void inOrder(Node *p) {
		if (p != NULL) {
			inOrder(p->getLlink());
			cout << p->getData() << endl;
			inOrder(p->getRlink());
		}		
	}

	void preOrder(Node *p) {
		if (p != NULL) {
			cout << p->getData() << endl;
			preOrder(p->getLlink());
			preOrder(p->getRlink());
		}
	}

	void postOrder(Node *p) {
		if (p != NULL) {
			postOrder(p->getLlink());
			postOrder(p->getRlink());
			cout << p->getData() << endl;
		}
	}

	int max(int a, int b) {
		if (a > b)
			return a;
		return b;
	}

	int height(Node* n) {
		if (n == NULL) {
			return -1;
		}
		else {
			return 1 + max(height(n->getLlink()), height(n->getRlink()));
		}
	}

	void preOrderTraversal() {
		preOrder(root);
	}

	void postOrderTraversal() {
		postOrder(root);
	}

	void inOrderTraversal() {
		inOrder(root);
	}

	int getHeight() {
		return height(root);
	}

	bool isEmpty() {
		return root == NULL;
	}
	
	void insert(int data) {
		Node* n = new Node(data);
		if (root == NULL) {		//if tree is empty then link new node with root
			root = n;
		}
		else {
			addNode(root, n);
		}
	}

	void addNode(Node *r, Node* n) {
		if ( r->getData() == n->getData()) {	//if item already exists
			return;			
		}
		else if (r->getData() > n->getData()) {	//item to be added is on left
			if (r->getLlink() == NULL) {
				r->setLlink(n);
				n->setParent(r);
			}
			else {
				addNode(r->getLlink(), n);
			}
		}
		else if ( (r->getData() < n->getData() )) {	//item to be added is on right side of tree
			if (r->getRlink() == NULL) {
				r->setRlink(n);
				n->setParent(r);
			}
			else {
				addNode(r->getRlink(), n);
			}
		}
	}

	void remove(int data) {
		Node* current;
		Node* pre;
		bool found = false;

		if (root->getData() == data) {		//if node to be deleted is the root node
			removeNode(root, data);			//then delete it
		}
		else {
			current = root;					//set current and pre pointes
			pre = root;

			while (current != NULL && found == false) {//loop until current is not null or found is not true
				if (current->getData() == data) {
					found = true;
				}
				else if (current->getData() > data) {
					pre = current;
					current = current->getLlink();
				}
				else if( current->getData() < data){
					pre = current;
					current = current->getRlink();
				}
			}

			if (found) {
				if (pre->getData() > data) {
					removeNode(pre->getLlink(), data);
				}
				else if (pre->getData() < data) {
					removeNode(pre->getRlink(), data);
				}
			}
		}
	}

	void removeNode(Node* n, int data) {
		if ( n->getLlink() == NULL && n->getRlink() == NULL ) {//If leaf node
			if(root == n){
				root =NULL;
			}
			else if(n->getParent()->getData() > data)	//if this is the left child of parent 
				n->getParent()->setLlink(NULL); //then set parent left pointer to right pointer of n
			else									//if this is the right child of parent
				n->getParent()->setRlink(NULL);//then set parent right pointer to right pointer of n
			delete n;//delete n
		}
		else if (n->getLlink() == NULL ) {
			if(root == n){
				root = n->getRlink();
			}
			else if (n->getParent()->getData() > data) {	//if this is the left child of parent 
				n->getParent()->setLlink(n->getRlink()); //then set parent left pointer to right pointer of n
				n->getRlink()->setParent(n->getParent());
			}
			else {									//if this is the right child of parent
				n->getParent()->setRlink(n->getRlink());//then set parent right pointer to right pointer of n
				n->getRlink()->setParent(n->getParent());
			}
			delete n;//delete n
		}//dry run done
		else if (n->getRlink() == NULL) {
			if(root == n){
				root = n->getLlink();
			}
			else if (n->getParent()->getData() > data) {	//if this is the left child of parent 
				n->getParent()->setLlink(n->getLlink()); //then set parent left pointer to left pointer of n
				n->getLlink()->setParent(n->getParent());
			}
			else {									//if this is the right child of parent
				n->getParent()->setRlink(n->getLlink());//then set parent right pointer to right pointer of n
				n->getLlink()->setParent(n->getParent());
				delete n;//delete n
			}
		}
		else {
			Node* current =n->getRlink();
			Node* pre= current;
			while(current != NULL){
				pre = current;
				current = current->getLlink();
			}
			
			n->setData(pre->getData());
			removeNode(pre, pre->getData());
		}
	}
};

int main()
{
	Tree t;
	t.insert(5);
	t.insert(6);

	t.remove(5);
	t.inOrderTraversal();
	system("PAUSE");
	return 0;
}
