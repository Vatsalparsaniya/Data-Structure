#include<stdio.h>
#include<stdlib.h>

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

int Search(struct BSTnode* Root,int Data){
  if(Root == NULL) return 0;
  if(Root->Data == Data) return 1;
  else if(Root->Data < Data) return Search(Root->RightNode,Data);
  else return Search(Root->LeftNode,Data);

/*  while(Data != Root->Data && Root != NULL){

    if(Data > Root->Data)
      Root = Root->RightNode;
    else
      Root = Root->LeftNode;
    }
    if(Root == NULL){
      printf("Node Not Avalable.....\n");
      return 0;
    }else{
      return 1;
    }*/

}

int FindMin(struct BSTnode *Root){
  if(Root->LeftNode == NULL)
    return Root->Data;
  else
    FindMin(Root->LeftNode);

/*  while(Root != NULL){
    Root = Root->LeftNode;
  }
  Return Root->Data;*/

}

int FindMax(struct BSTnode *Root){
  if(Root->RightNode == NULL)
    return Root->Data;
  else
    FindMax(Root->RightNode);

/*  while(Root != NULL){
    Root = Root->RightNode;
  }
  return Root->Data;*/
}

int MaxHight(struct BSTnode *Root){
  int L_Hight=0,R_Hight=0;
  if(Root == NULL)
    return -1;
  if(Root->LeftNode == NULL && Root->RightNode == NULL)
    return 0;
  L_Hight = MaxHight(Root->LeftNode);
  R_Hight = MaxHight(Root->RightNode);
  if(L_Hight > R_Hight)
    return L_Hight+1;
  else
    return R_Hight+1;
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

struct BSTnode * DeleteNode(struct BSTnode* Root,int key){
struct BSTnode *Temp;
  if(Root == NULL )
    return Root;
  if(key > Root->Data)
    Root->RightNode = DeleteNode(Root->RightNode,key);
  else if(key < Root->Data)
    Root->LeftNode = DeleteNode(Root->LeftNode,key);
    else{ // Root->Data == key;
      if(Root->LeftNode == NULL && Root->RightNode == NULL){
        // node with 0 child
        free(Root);
        return NULL;
      }
      else if(Root->LeftNode == NULL){
        // node with 1 child
        Temp = Root->RightNode;
        free(Root);
        return Temp;
      }else if(Root->RightNode == NULL){
        // node with 1 child
        Temp = Root->LeftNode;
        free(Root);
        return Temp;
      }else{
        // node with 2 childe
        // find min in right sub-Tree
        Temp = Root->RightNode;
        while(Temp->LeftNode != NULL){
          Temp = Temp->LeftNode;
        }
        Root->Data = Temp->Data;
        Root->RightNode = DeleteNode(Root->RightNode,Temp->Data);
      }
      return Root;
    }

}

int main(){
  int c,n,i;
  struct BSTnode *Root= NULL;
  printf("1) InsertNode\n2) Hight of Tree\n3) Find Max Data\n4) Find Min Data\n5) Search Data\n6) INORDER_Traversal\n7) PREORDER_Traversal\n8) POSTORDER_Traversal\n9) LEVELORDER_Traversal\n10) DeleteNode\n11) Exit\n\n");
  while (c != 11) {
    printf("Enter Your choice :");
    scanf("%d",&c);
    switch (c) {
      case 1:
        printf("Enter Data :");
        scanf("%d",&n);
        Root = InsertNode(Root,n);
        break;
      case 2:
        i = MaxHight(Root);
        printf("Hight Of tree is %d\n",i);
        break;
      case 3:
        i = FindMax(Root);
        printf("Max Data of Tree is %d\n",i);
        break;
      case 4:
        i = FindMin(Root);
        printf("Min Data of tree is %d\n",i);
        break;
      case 5:
        printf("Find Data in Tree :");
        scanf("%d",&n);
        i= Search(Root,n);
        if(i == 1){
          printf("Data found\n");
        }else{
          printf("Data Not found\n");
        }
        break;
      case 6:
        printf("INORDER_Traversal of Tree is....");
        INORDER_Traversal(Root);
        printf("\n");
        break;
      case 7:
        printf("PREORDER_Traversal of Tree is....");
        PREORDER_Traversal(Root);
        printf("\n");
        break;
      case 8:
        printf("POSTORDER_Traversal of Tree is....");
        POSTORDER_Traversal(Root);
        printf("\n");
        break;
      case 9:
        printf("LEVELORDER_Traversal of Tree is....");
        LEVELORDER_Traversal(Root);
        break;
      case 10:
        printf("which Node you want to delete :");
        scanf("%d",&n);
        DeleteNode(Root,n);
        break;
      case 11:
        exit(0);
      break;
      default:
          printf("Enter valid choice between 1-10\n");
      break;
    }

  }
  return 0;
}
