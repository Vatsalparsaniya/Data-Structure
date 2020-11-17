#include<stdio.h>
#include<stdlib.h>

struct AVLnode{
  int Data;
  int Hight;
  struct AVLnode* LeftNode;
  struct AVLnode* RightNode;
};
int GetHight(struct AVLnode* Node){
  if(Node == NULL)  return -1;
  if(Node->LeftNode == NULL && Node->RightNode == NULL) return 0;
  int Hight,LeftChild_Hight,RightChild_Hight;
  LeftChild_Hight = GetHight(Node->LeftNode);
  RightChild_Hight = GetHight(Node->RightNode);
  if(LeftChild_Hight > RightChild_Hight)
    return LeftChild_Hight+1;
  else
    return RightChild_Hight+1;
}
int GetBalance(struct AVLnode * Node){
  if(Node == NULL)  return 0;
  return GetHight(Node->LeftNode)-GetHight(Node->RightNode);
}


struct AVLnode *SingleRightRotation(struct AVLnode *Parent){
    struct AVLnode* LeftChild;
     LeftChild = Parent->LeftNode;
     Parent->LeftNode = LeftChild->RightNode;
     LeftChild->RightNode = Parent;
     Parent->Hight =GetHight(Parent);
     LeftChild->Hight = GetHight(LeftChild);
     return LeftChild;
}
struct AVLnode *SingleLeftRotation(struct AVLnode *Parent){
    struct AVLnode* RightChild;
     RightChild = Parent->RightNode;
     Parent->RightNode = RightChild->LeftNode;
     RightChild->LeftNode = Parent;
     Parent->Hight =GetHight(Parent);
     RightChild->Hight = GetHight(RightChild);
     return RightChild;
}
struct AVLnode *DobleLeftRightRotation(struct AVLnode *Parent){
struct AVLnode *LeftChild;;
  LeftChild = Parent->LeftNode;
  Parent->LeftNode = SingleLeftRotation(Parent->LeftNode);
  Parent = SingleRightRotation(Parent);
  return Parent;
}
struct AVLnode *DobleRightLeftRotation(struct AVLnode *Parent){
  Parent->RightNode = SingleRightRotation(Parent->RightNode);
  Parent = SingleLeftRotation(Parent);
  return Parent;
}

struct AVLnode* InsertNode(struct AVLnode* Root,int val){
  if(Root == NULL){
    struct AVLnode *NewNode;
    NewNode = (struct AVLnode*)malloc(sizeof(struct AVLnode));
      if(NewNode == NULL){
        printf(" Sorry! malloc is fail\n");
        return Root;
      }
      NewNode->Data = val;
      NewNode->Hight = 0;
      NewNode->LeftNode = NULL;
      NewNode->RightNode = NULL;
      return NewNode;
      }
    if(val < Root->Data){
      Root->LeftNode = InsertNode(Root->LeftNode,val);
      if(GetBalance(Root) == 2){
        // heavy Left Sub-tree
        if(val < (Root->LeftNode)->Data){
          // left-left case
          Root = SingleRightRotation(Root);
        }else{
          // left-Right case
          Root = DobleLeftRightRotation(Root);
        }
      }
    }else{
      Root->RightNode = InsertNode(Root->RightNode,val);
      if(GetBalance(Root) == -2){
        // right-sub tree heavy
        if(val > (Root->RightNode)->Data){
          // right - right case
          Root= SingleLeftRotation(Root);
        }else{
          // right - left case
          Root = DobleRightLeftRotation(Root);
        }
      }
    }

  Root->Hight = GetHight(Root);
  return Root;
}

struct AVLnode* DeleteNode(struct AVLnode* Root,int val){
  struct AVLnode *temp;
  int Balance;
  if(Root == NULL)  return Root;
  else if(val < Root->Data)
    Root->LeftNode = DeleteNode(Root->LeftNode,val);
  else if(val > Root->Data)
    Root->RightNode = DeleteNode(Root->RightNode,val);
  else{
    // Root->Data == val
    if(Root->LeftNode == NULL &&  Root->RightNode == NULL){
      // Node with 0 childe
      free(Root);
      return NULL;
    }else if(Root->LeftNode == NULL){
      // Node with only Right child
      temp = Root->RightNode;
      free(Root);
      return temp;
    }else if(Root->RightNode == NULL ){
      // Node with only Left Child
      temp = Root->LeftNode;
      free(Root);
      return temp;
    }else{
      // Node with 2 child
      temp = Root->RightNode;
      while(temp->LeftNode != NULL){
        temp = temp->LeftNode;
      }
      printf("%d\n",temp->Data);
      Root->Data = temp->Data;
      Root->RightNode = DeleteNode(Root->RightNode,temp->Data);
    }
    if(GetBalance(Root)== 2){
      if(GetBalance(Root->LeftNode)>0){
        //left-left case
        return SingleRightRotation(Root);
      }else{
        // left-right case
        return DobleLeftRightRotation(Root);
      }
    if(GetBalance(Root)== -2){
      if(GetBalance(Root->RightNode)<0){
        // Right-right case
        return SingleRightRotation(Root);
      }else{
        //Right-left case
        return DobleLeftRightRotation(Root);
      }
    }
    }
  }
  return Root;
}
void INORDER_Traversal(struct AVLnode *Root){
  if(Root == NULL)
  return;
  INORDER_Traversal(Root->LeftNode);
  printf("%d ",Root->Data);
  INORDER_Traversal(Root->RightNode);
}
void PREORDER_Traversal(struct AVLnode *Root){
  if(Root == NULL)
  return;
  printf("%d ",Root->Data);
  PREORDER_Traversal(Root->LeftNode);
  PREORDER_Traversal(Root->RightNode);
}

 void POSTORDER_Traversal(struct AVLnode *Root){
   if(Root == NULL)
   return;
   POSTORDER_Traversal(Root->LeftNode);
   POSTORDER_Traversal(Root->RightNode);
   printf("%d ",Root->Data);
}
int front=-1,rear=-1;
#define MaxSize 100
struct AVLnode* Q[MaxSize];

void InQueue(struct AVLnode* Data){
  if(rear == MaxSize){
    printf("Sorry Queue is Full\n");
  }else{
    if(front == -1 ) front++;
    Q[++rear] = Data;
  }
}

struct AVLnode* Dequeue(){
  //if(front == -1) return
  if(front == rear){
    struct AVLnode* r = Q[front];
    front = -1;
    rear = -1;
    return r;
  }else{
  return Q[front++];
  }
}

void LEVELORDER_Traversal(struct AVLnode *Root){
  InQueue(Root);
  struct AVLnode *Temp;
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
  int Search(struct AVLnode* Root,int Data){
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


int main(){
  int c,n,i;
  struct AVLnode *Root= NULL;
  printf("1) InsertNode\n2) Hight of Tree\n3) Search Data\n4) INORDER_Traversal\n5) PREORDER_Traversal\n6) POSTORDER_Traversal\n7) LEVELORDER_Traversal\n8) DeleteNode\n9) Exit\n\n");
  while(c != 9) {
    printf("Enter Your choice :");
    scanf("%d",&c);
    switch (c) {
      case 1:
        printf("Enter Data :");
        scanf("%d",&n);
        Root = InsertNode(Root,n);
        break;
      case 2:
        i = GetHight(Root);
        printf("Hight Of tree is %d\n",i);
        break;
      case 3:
        printf("Find Data in Tree :");
        scanf("%d",&n);
        i= Search(Root,n);
        if(i == 1){
          printf("Data found\n");
        }else{
          printf("Data Not found\n");
        }
        break;
      case 4:
        printf("INORDER_Traversal of Tree is....");
        INORDER_Traversal(Root);
        printf("\n");
        break;
      case 5:
        printf("PREORDER_Traversal of Tree is....");
        PREORDER_Traversal(Root);
        printf("\n");
        break;
      case 6:
        printf("POSTORDER_Traversal of Tree is....");
        POSTORDER_Traversal(Root);
        printf("\n");
        break;
      case 7:
        printf("LEVELORDER_Traversal of Tree is....");
        LEVELORDER_Traversal(Root);
        break;
      case 8:
        printf("which Node you want to delete :");
        scanf("%d",&n);
        DeleteNode(Root,n);
        break;
      case 9:
        exit(0);
      break;
      default:
          printf("Enter valid choice between 1-10\n");
      break;
    }

  }
  return 0;
}
