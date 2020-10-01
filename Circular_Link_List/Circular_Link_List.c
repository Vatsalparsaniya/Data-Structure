#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *ptr;
};

struct node* insertOrder(struct node *head,int val){
    struct node* newNode,*temp;
    temp = head;
    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->value = val;

    if(head == NULL){
        newNode->ptr = newNode;
        head = newNode;
    }
    else if(val <= head->value){
        newNode->ptr = head;

        while(temp->ptr != head)
            temp = temp->ptr;

        head = newNode;    // initialize head part here always
        temp->ptr = head;
    }
    else{
        while(temp->ptr != head && val > temp->ptr->value)
            temp = temp->ptr;

        newNode->ptr = temp->ptr;
        temp->ptr = newNode;
    }
    return head;
}


struct node* deleteVal(struct node* head,int val){
    struct node* temp,*nodeDeleted;
    temp = head;
    if(head == NULL){
        printf("List is empty\n");
    }
    else if(head->value == val){
        while(temp->ptr != head) {
            temp = temp->ptr;
        }
        temp->ptr = head->ptr;
        free(head);
        head = temp->ptr;
    }
    else{
        temp = head;
        while (temp->ptr != head && val != temp->ptr->value) {
            temp = temp->ptr;
        }

        if(temp->ptr == head)
            printf("Given value is not Found\n");
        else{
            nodeDeleted = temp->ptr;
            temp->ptr = temp->ptr->ptr;
            free(nodeDeleted);
        }
    }
    return head;
}

void display(struct node* head){
    struct node*temp = head;
    if(head == NULL)
        printf("The list is Empty\n");
    else{
        do{
            printf("%d ",temp->value);
            temp = temp->ptr;
        } while(temp != head);
        printf("\n");
    }
}

void main(){
    struct node * head;
    head= NULL;
    int n,val;

    printf("Enter 1 for insert in order\n");
    printf("Enter 2 for delete value\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!= 4){
    switch(n){
    case 1:
        printf("Enter value you want to inserted\n");
        scanf("%d",&val);
        head = insertOrder(head,val);
        break;
    case 2:
        printf("Enter value you want to delete\n");
        scanf("%d",&val);
        head = deleteVal(head,val);
        break;
    case 3:
        display(head);
        break;
    default:
        printf("Enter proper value\n");
    }
    printf("Enter 1/2/3/4\n");
    scanf("%d",&n);
    }

}
