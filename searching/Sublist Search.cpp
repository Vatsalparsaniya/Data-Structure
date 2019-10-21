// C++ program to find if a list is present in another list
#include <bits/stdc++.h> 
using namespace std; 

// A Linked List node 
struct Node 
{ 
	int data; // To store Data
	Node* next; 
}; 

// Returns true if first list is present in second 
// list 
bool findList(Node* first, Node* second) 
{ 
	Node* ptr1 = first, *ptr2 = second; 

	// To return true if both linked lists are empty 
	if (first == NULL && second == NULL) 
		return true; 

	// To return false if one list is empty and other list is not empty
	if ( first == NULL || 
		(first != NULL && second == NULL)) 
		return false; 

	// To traverse the second list one by one
	while (second != NULL) 
	{ 
		// Initialize ptr2 with value of current node of second 
		ptr2 = second; 

		// Matching first list with second list 
		while (ptr1 != NULL) 
		{ 
			// If second list becomes empty and first not then return false 
			if (ptr2 == NULL) 
				return false; 

			// If data part is same, go to next of both lists 
			else if (ptr1->data == ptr2->data) 
			{ 
				ptr1 = ptr1->next; 
				ptr2 = ptr2->next; 
			} 
			// If not equal then break the loop 
			else break; 
		} 

		// Return true if first list gets traversed completely that means it is matched. 
		if (ptr1 == NULL) 
			return true; 

		// Initialize ptr1 with first again 
		ptr1 = first; 

		// And go to next node of second list 
		second = second->next; 
	} 

	return false; 
} 

// function to print all nodes of the list
void printList(Node* node) 
{ 
	while (node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

// Function to add new node to linked lists 
Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp-> data= key; 
	temp->next = NULL; 
	return temp; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	/* Let us create two linked lists to test 
	the above functions. Created lists shall be 
		a: 1->2->3->4 
		b: 1->2->1->2->3->4*/
	Node *a = newNode(1); 
	a->next = newNode(2); 
	a->next->next = newNode(3); 
	a->next->next->next = newNode(4); 

	Node *b = newNode(1); 
	b->next = newNode(2); 
	b->next->next = newNode(1); 
	b->next->next->next = newNode(2); 
	b->next->next->next->next = newNode(3); 
	b->next->next->next->next->next = newNode(4); 

	findList(a,b) ? cout << "LIST FOUND" : cout << "LIST NOT FOUND"; 

	return 0; 
} 