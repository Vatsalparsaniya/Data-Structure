#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedList
{
private:
    int size;
    node *head;
    
public:
    LinkedList(){
        head=NULL;
        size=0;
    }

    
    void insert(int x){
        //Create a new node to be inserted
        node *temp;temp= new node();
        temp->data=x;
        temp->next=NULL;
        size++;
        //Check if list is empty
        if(head == NULL){
            head=temp;
        }
        else{
            node *t;
            t=head;
            //Insert at beginning if x is smallest in linked list
            if(head->data>x){
                temp->next=head;
                head=temp;
            }
            else{
            //Get the pointer at which position the new node is to be inserted
            while(t->next!=NULL && x>t->next->data){
                t=t->next;
            }
            //Perform the insertion
            temp->next=t->next;
            t->next=temp;
            }
        }
    }

    void delete_first(){
    if(size==0){
        cout<<"List Empty\n";
        return;
    }
    size--;
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
    }

    void delete_last(){
    if(size==0){
        cout<<"List Empty\n";
        return;
    }
    size--;
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
      previous=current;
      current=current->next;	
    }
    previous->next=NULL;
    delete current;
    }

    void delete_position(int pos){
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
    }

    // Utility function to display all elements in the linked list
    void display1(){
        node *t;
        t=head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        // cout<<t->data<<" ";
        return;
    }
};

// Driver Code
int main(){
    LinkedList l;
    l.insert(5);
    l.insert(2);
    l.insert(15);
    l.insert(12);
    l.display1();
    return 0;

}

