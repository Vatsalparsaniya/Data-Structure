// CPP Program to convert postfix to prefix 
#include <iostream> 
#include <stack> 
using namespace std; 

// Utility function to check if character is operator or not 
bool isOperator(char x) 
{ 
	switch (x) { 
	case '+': 
	case '-': 
	case '/': 
	case '*': 
		return true; 
	} 
	return false; 
} 

// Convert postfix to prefix expression 
string postToPre(string post_exp) 
{ 
	stack<string> s; 
	int i,l = post_exp.size(); 

	// reading from right to left 
	for (i = 0; i < l; i++) { 

		// check if symbol is operator 
		if (isOperator(post_exp[i])) { 

			// pop two operands from stack 
			string op1 = s.top(); 
			s.pop(); 
			string op2 = s.top(); 
			s.pop(); 

			// concat the operands and operator 
			string temp = post_exp[i] + op2 + op1; 

			// Push string temp back to stack 
			s.push(temp); 
		} 

		// if symbol is an operand push the operand to the stack 
		else { 
			s.push(string(1, post_exp[i])); 
		} 
	} 

	// The stack now contains the prefix expression 
	return s.top(); 
} 
 
int main() 
{ 
	string post;
    cout<<"Enter the postfix expression: ";
    cin>>post;
	cout << "The prefix expression is: " << postToPre(post)<<"\n"; 
	return 0; 
} 
