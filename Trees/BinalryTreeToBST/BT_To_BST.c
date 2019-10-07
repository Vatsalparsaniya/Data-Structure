#include<stdio.h>
#include<stdlib.h>
int current = 0;
struct BSTnode{
  int Data;
  struct BSTnode* LeftNode;
  struct BSTnode* RightNode;
};

 struct BSTnode* InsertNode(struct BSTnode* Root,int Data){
  struct BSTnode *temp,*NewNode;
  NewNode = (struct BSTnode*)malloc(sizeof(struct BSTnode));
  if(NewNode == NULL){
    printf("Sorry Malloc is fail...!!!\n");
    return Root;
  }

  NewNode->Data = Data;
  NewNode->LeftNode = NULL;
  NewNode->RightNode = NULL;


  temp = Root;

  /*while (temp != NULL ) {
    if(temp->Data > Root->Data){
      temp = Root->RightNode;
    }else{
      temp = Root->LeftNode;
    }
  }
  temp = NewNode;*/

  if(Root == NULL){
    Root = NewNode;
    return Root;
  }else if(Data > Root->Data){
    Root->RightNode = InsertNode(Root->RightNode,Data);
  }else{
    Root->LeftNode = InsertNode(Root->LeftNode,Data);
  }
  return temp;
}
void INORDER_Traversal(struct BSTnode *Root){
  if(Root == NULL)
  return;
  INORDER_Traversal(Root->LeftNode);
  printf("%d ",Root->Data);
  INORDER_Traversal(Root->RightNode);
}

void PREORDER_Traversal(struct BSTnode *Root){
  if(Root == NULL)
  return;
  printf("%d ",Root->Data);
  PREORDER_Traversal(Root->LeftNode);
  PREORDER_Traversal(Root->RightNode);
}

 void POSTORDER_Traversal(struct BSTnode *Root){
   if(Root == NULL)
   return;
   POSTORDER_Traversal(Root->LeftNode);
   POSTORDER_Traversal(Root->RightNode);
   printf("%d ",Root->Data);
}
int front=-1,rear=-1;
#define MaxSize 100
struct BSTnode* Q[MaxSize];

void InQueue(struct BSTnode* Data){
 if(rear == MaxSize){
   printf("Sorry Queue is Full\n");
 }else{
   if(front == -1 ) front++;
   Q[++rear] = Data;
 }
}

struct BSTnode* Dequeue(){
 //if(front == -1) return
 if(front == rear){
   struct BSTnode* r = Q[front];
   front = -1;
   rear = -1;
   return r;
 }else{
 return Q[front++];
 }
}

void LEVELORDER_Traversal(struct BSTnode *Root){
 InQueue(Root);
 struct BSTnode *Temp;
 while (front != -1) {
   Temp = Dequeue();
   if( Temp != NULL ){
     InQueue(Temp->LeftNode);
     InQueue(Temp->RightNode);
     printf("%d ",Temp->Data);
     }
   }
   printf("\n");
 }
int main(){
  struct BSTnode*Root = NULL;
  int n[100]={0},c,h=0;
  printf("1) InsertNode In Binary tree in LEVELORDER\n2) Convert Tree in Binary-Search-Tree Display in INORDER_Traversal\n");
  printf("3) Convert Tree in Binary-Search-Tree Display in PREORDER_Traversal\n4) Convert Tree in Binary-Search-Tree Display in POSTORDER_Traversal\n");
  printf("5) Convert Tree in Binary-Search-Tree Display in LEVELORDER_Traversal\n6) Exit\n");
  while(c != 6){
    printf("Enter your choice :");
    scanf("%d",&c);
    switch (c) {
      case 1:
        printf("Enter Node in Binary Value in LEVELORDER: ");
        scanf("%d",&n[current++]);
      break;
      case 2:
       h=0;
        printf("your Binary-Search-Tree in INORDER_Traversal is...");
        while (n[h] != 0) {
        Root= InsertNode(Root,n[h++]);
        }
        INORDER_Traversal(Root);
        Root = NULL;
        printf("\n");
      break;
      case 3:
       h=0;
      printf("your Binary-Search-Tree in PREORDER_Traversal is...");
      while (n[h] != 0) {
      Root= InsertNode(Root,n[h++]);
      }
      PREORDER_Traversal(Root);
      printf("\n");
      Root = NULL;
      break;
      case 4:
       h=0;
      printf("your Binary-Search-Tree in POSTORDER_Traversal is...");
      while (n[h] != 0) {
      Root= InsertNode(Root,n[h++]);
      }
      POSTORDER_Traversal(Root);
      Root = NULL;
      printf("\n");
      break;
      case 5:
       h=0;
      printf("your Binary-Search-Tree in LEVELORDER_Traversal is...");
      while (n[h] != 0) {
      Root= InsertNode(Root,n[h++]);
      }
      LEVELORDER_Traversal(Root);
      Root = NULL;
      break;
      case 6:
        exit(0);
        break;
    }
  }
  return 0;
}
