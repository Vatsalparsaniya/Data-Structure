 #include<iostream>
 using namespace std;
 class node{
 public:
 int data;
 node* next;
 node(int data){
 this->data=data;
 next=NULL;
 }
 };
 node*last;
 node* takeInput(int n){
 int data;
 node*head=NULL;
 node*p=NULL;
 for(int i=0;i<n;i++){
 cin>>data;
 node* newNode=new node(data);
 if(i==0){
 head=newNode;
 p=head;
 }
 else{
 p->next=newNode;
 p=p->next;
 }
 }
 last=p;
 last->next=head;
 return head;
 }
 node* insert_after(node*head,int element,int data){
 node*temp=head->next;
 if(last->data==element){
   node* newNode=new node(data);
   last->next=newNode;
   last=last->next;
   newNode->next=head;
   return head;
 }
 if(head->data==element){
    node*q=head->next;
    node* newNode=new node(data);
    head->next=newNode;
    newNode->next=q;
    return head;
 }
 else{
    while(temp!=head){
      node*p=temp->next;
      if(temp->data==element){
         node* newNode=new node(data);
         temp->next=newNode;
         newNode->next=p;
         return head;
 }
    temp=temp->next;
 }
 }
 }
 node* delete_cll(node*head,int data){
    node*temp=head->next;
    node*previous=head;
    if(head->data==data){
       head=head->next;
       last->next=head;
       return head;
    }
    else{
        while(temp!=head){
           if(temp->data==data){
              if(temp==last){
                 previous->next=head;
                 last=previous;
                 return head;
              }
              else{
                 previous->next=temp->next;
                 return head;
              }
           }
           previous=temp;
           temp=temp->next;
        }

    }
 }
 void print(node*head){
 cout<<head->data<<" ";
 node*temp=head->next;
 while(temp!=head){
 cout<<temp->data<<" ";
 temp=temp->next;
 }
 }

 int main(){
 node*head;
 int n;
 cout<<"Enter limit:";
 cin>>n;
 head=takeInput(n);
 print(head);
 cout<<"\n";
 cout<<"\nEnter data to be inserted and the position after which it is to be inserted";
 int data;
 cin>>data;
 int element;
 cin>>element;
 head=insert_after(head,element,data);
 cout<<"\nAfter insertion:";
 print(head);
 cout<<"\nEnter element to be deleted";
 int el_del;
 cin>>el_del;
 head=delete_cll(head,el_del);
 cout<<"\nAfter deletion:";
 print(head);
 }

