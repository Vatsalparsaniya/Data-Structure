#include <bits/stdc++.h>
using namespace std;

//Node class used as building block for Stack Class/Object
template<typename T>
class Node{
	T data;
	Node<T>* next;
	public:
		Node<T>(T num){
			data = num;
			next = NULL;
		}
		T getData(){
			return data;
		}
		Node<T>* getNext(){
			return next;
		}	
		void setData(T num){
			data = num;
		}
		void setNext(Node* temp){
			next = temp;
		}
};
template <typename T>
class Stack{
	Node<T>* head;
	public:
		Stack(){
			head = NULL;
		}
		void push(T data){
			if(head == NULL){
				head = new Node<T>(data);
				return;
			}
			Node<T>* temp = new Node<T>(data);
			temp->setNext(head);
			head = temp;
		}
		void pop(){
			if(isEmpty())
				return;
			Node<T>* temp = head;
			head = head->getNext();
			delete temp;
		}
		T top(){
			return head->getData();
		}
		bool isEmpty(){
			return (head == NULL)?true:false;
		}
		void print(){
			Node<T>* temp = head;
			while(temp != NULL){
				cout<<temp->getData()<<" ";
				temp = temp->getNext();
			}
		}
};
bool balanced(string str){
	Stack<char> s;
	for(int i=0; i<str.length(); i++){
		if(str[i] == '{' || str[i] == '(' || str[i] == '[')
			s.push(str[i]);
		else if(!s.isEmpty() && (str[i] == '}' && s.top() == '{')|| (str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '['))
			s.pop();
		else
			return false;
	}
	
	return s.isEmpty();	
}
int main(){
	//An application on how stack can be useful to check standard Balanced bracket problem
	string str;
	char choice;
	do{
		cin>>str;
		(balanced(str))?cout<<"Balanced":cout<<"Not Balanced";
		cout<<"\nDo you want to try again?(y/n) ";
		cin>>choice;
	}while(choice != 'n');
	return 0;
}
