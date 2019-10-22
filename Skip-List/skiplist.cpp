/*
Author: Parag Ghorpade
PROBLEM STATEMENT: For a given set of elements , create a skip list. Find the element in the set that is closest to some given value.
 */

#include<iostream>
#include<stdlib.h>
using namespace std;
int a[10];
struct link
{
	link *rlink, *uplink, *next;
	int data;

}*head;
	class skip_list
	{
	public:
		void create(int);
		void display();
		int closest(int);
	};


void skip_list::create(int n)
{
	link *p=NULL;
	head=NULL;
	int half=n/2;
	int temp;
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n-1-i;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	}
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head =new link;
			head->data=a[i];
			p=head;
		}
		else
		{
			p->next=new link;
			p=p->next;
			p->data=a[i];
		}
		if(i==half)
		{
		head->rlink=p;
		}
	}
	head->rlink->rlink=p;
	head->uplink=p;
}


void skip_list::display()
{
link *q;
cout<<"Displaying skip list...\n(no. of jumps are two-:\n i>from first->middle->last\n ii>from first->last element)\n\n";
cout<<"elements of skip list (in ascending order):";
cout<<"connections for first lane :\n";
for(q=head;q->next!=NULL;q=q->next)
{
	cout<<"["<<q->data<<"]->";
	}
	cout<<"["<<q->data<<"]"<<endl;

cout<<"\n";
cout<<"connections for second lane(express lane) :"<<endl;
cout<<"["<<head->data<<"]->["<<head->rlink->data<<"]->["<<head->rlink->rlink->data<< "]"<<endl;
cout<<"\n";
cout<<"connections for third lane(express lane) :"<<endl;
cout<<"["<<head->data<<"]->["<<head->uplink->data<<"]"<<endl;
}


int skip_list::closest(int num)
{
	link *q;
	q=head;
	int result=-1,res1,answer;
	if(num==q->data)
		{
			return q->data;
		}
	if(num<q->data)
		{
			return q->data;
		}
	if(num==q->uplink->data)
	{
		return q->uplink->data;
	}
	if(num>q->uplink->data)
	{
		return q->uplink->data;
	}
	if(num==q->rlink->data)
	{
		return q->rlink->data;
	}
	if(num>q->rlink->data)
	{

		result=num-q->rlink->data;
		answer=q->rlink->data;
		q=q->rlink->next;

	}
	for(;q->data<=num;q=q->next)
	{

		res1=num-q->data;
		if(result==-1 || abs(res1)<abs(result))
		result=res1;
		answer=q->data;
	}
	res1=q->data-num;
	if(abs(res1)<abs(result))
	{
		result=res1;
		answer =q->data;
	}
	return answer;
}


int main()
{
int n,num;
int flag=0,ch;
char ans='y';
skip_list a1;
	do
	{
	cout<<"MENU\n\t1)create list\n\t2)find the closest element\n3)display\nenter your choice\n";
	cin>>ch;
	switch(ch)
	{

	case 1:
		flag=1;
		cout<<"enter the number of elements in the list :";
		cin>>n;
		cout<<"enter the elements in the skip list formed :";
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		}
		a1.create(n);
		break;
	case 2:
		if(flag==0)
		{
			cout<<"no list nearest list is present...";
			break;
		}
		cout<<"enter the element for which closest value is to be found :";
		cin>>num;
		cout<<"the closest element is :"<<a1.closest(num);
		break;
	case 3:{
					a1.display();
		}
	}
	cout<<"\ndo u want to continue [Y/N]:";
	cin>>ans;
	}
	while(ans=='y');
	return 0;
	}


