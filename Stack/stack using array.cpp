#include<bits/stdc++.h>
using namespace std;
void display(int ar[],int &top)
{
	
	for(int i=top;i>=0;i--){
	cout<<" "<<ar[i];
	
	
	}
	
}
void push (int ar[],int &top,int x)
{
	if(top>=20)
	cout<<"Stack Overflow";
	else 
	ar[++top]=x;
	display(ar,top);
		
}
void pop(int ar[],int &top){
	
	if(top<=-1)
	cout<<"\n Stack underflow";
	else
	{
		cout<<ar[top]<<"popped\n";
		top--;
	}
	display(ar,top);
	
}
int main(){
	
int ar[20],top=-1,x;
int n;
char ch;

do{
	
	cout<<"\nEnter 1 to push element";
	cout <<"\nEnter 2 to pop element";
	cout<<"\nEnter 3 for traversal";
	cout <<"\nEnter 4 to exit";
	cout<<"\nEnter your choice:";
	cin>>n;
	switch(n){
		
	case 1: cout<<"Enter the number:";
            cin>>x;
	        push(ar,top,x);
	        break;
    case 2: pop(ar,top);
            break;
    case 3: display(ar,top);
	         break;
    case 4: exit(0);
	
}

   }while(1);
	
	return 0;
}
	
	

