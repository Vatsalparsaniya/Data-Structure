#include <iostream>
using namespace std;
class Node {
   public:
   char data;
   Node* left, * right;
};
//Creating the tree
Node* binaryCreate(char data) {
   Node* node = new Node;
   node->data = data;
   node->left = node->right = NULL;
   return node;
}
//For subsequent elements
Node* find(char data) {
   Node* node = new Node;
   node->data = data;
   node->left = node->right = NULL;
   return node;
}
//To insert element into the tree
Node* binaryInsert(char arr[], Node* next, int i, int size) {
   if (i < size) {
      Node* temp = find(arr[i]);
      next = temp;
      next->left = binaryInsert(arr, next->left, 2 * i + 1, size);
      next->right = binaryInsert(arr, next->right, 2 * i + 2, size);
   }
   return next;
}

//To find and print element
void binaryPrint(Node* next, char val) {
	char key = val;
	if(next != NULL){
		binaryPrint(next->left, key);
		if(next->data==val){
			cout << next->data << " ";
		}
		binaryPrint(next->right, key);
	}
}

void binaryTrav(Node* next) {
   if (next != NULL){
      binaryTrav(next->left);
      cout << next->data <<" ";
      binaryTrav(next->right);
   }
}
//Main function
int main() {
   char chars[] = {'B','D','R','T','E','M','N','P'}; //input into the tree
   int key;
   char val;
   Node* root = binaryCreate(chars[0]);
   int n = sizeof(chars)/sizeof(chars[0]);
   root = binaryInsert(chars, root, 0, n);
   cout << "Inorder traversal:";
   binaryTrav(root);
   cout << "Enter index of element for searching";
   cin >> key;
   val = chars[key];
   binaryPrint(root, chars[key]);
   
}
