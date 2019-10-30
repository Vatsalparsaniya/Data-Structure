#include <iostream>
using namespace std;
struct Node { 
   int val; 
   struct Node *next; 
}; 
struct Node* head = NULL;   
void insert(int new_val) { 
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
   new_node->val = new_val; 
   new_node->next = head; 
   head = new_node; 
} 
void printLinkedList() { 
   struct Node* pointer;
   pointer = head;
   while (pointer != NULL) { 
      cout<< pointer->val <<" "; 
      pointer = pointer->next; 
   } 
} 
int main() { 
   insert(43);
   insert(13);
   insert(73);
   insert(22);
   insert(92);
   cout<<"The linked list is: ";
   printLinkedList(); 
   return 0; 
} 
