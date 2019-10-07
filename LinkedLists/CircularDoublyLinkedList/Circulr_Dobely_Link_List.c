#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* lptr;
    struct Node* rptr;
};

void insert_front(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        newNode->lptr= newNode;
        newNode->rptr= newNode;
        *L=*R=newNode;
        return;
    }
    newNode->rptr = *L;
    newNode->lptr = *R;
    (*L)->lptr = newNode;
    *L = newNode;
    (*R)->rptr = *L;    // make circular List
}

void insert_rear(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        newNode->lptr= newNode;
        newNode->rptr= newNode;
        *L=*R=newNode;
        return;
    }
    newNode->lptr = *R;
    newNode->rptr = *L;
    (*R)->rptr = newNode;
    *R = newNode;
    (*L)->lptr = *R;      //make Circular List
}

void insert_order(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    struct Node* temp = *L;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        newNode->lptr= newNode;
        newNode->rptr= newNode;
        *L=*R=newNode;
        return;
    }

    if(val <= (*L)->value){
        newNode->rptr = *L;
        newNode->lptr = *R;
        (*L)->lptr = newNode;
        *L = newNode;
        (*R)->rptr = *L;
    }
    else if(val >= (*R)->value){
        newNode->lptr = *R;
        newNode->rptr = *L;
        (*R)->rptr = newNode;
        *R = newNode;
        (*L)->lptr = *R;
    }
    else{
        while(temp->value <= val)
            temp = temp->rptr;

        newNode->lptr = temp->lptr;
        newNode->rptr = temp;
        temp->lptr->rptr = newNode;
        temp->lptr = newNode;
    }
}

void insert_specs(struct Node**L,struct Node**R,int val){
    int sval,n;
    struct Node* newNode;
    struct Node* temp = *L;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;
    //here our list is not empty because user give us value which we have to put after some value,
    //so the list is not empty and we dont have to write condition for null list

    do{
    printf("Enter after which value you want to insert:\n");
    scanf("%d",&sval);
    n=1; //initialize n here.
    temp = *L; //initialize temp also because if one time value not found then temp comes to head part again for new loop
    while(temp->value != sval){
        temp = temp->rptr;

        if(temp== NULL){ //this condition is special because written in while loop
            printf("your given value is not found\n");
            n=0;
            break;
        }
    }
    }while(n==0);

    newNode->lptr = temp;
    newNode->rptr = temp->rptr;
    if(temp != *R)  temp->rptr->lptr = newNode; // write this always above the below sentences.
    temp->rptr = newNode;

    if(temp == *R){ //upgradation of rear and front value
        *R = newNode;
        (*L)->lptr = *R;
    }
}


void del_front(struct Node** Head,struct Node ** Rear){
	struct Node * delete;

	if(*Head == NULL){
		printf("The list is Empty\n");
		return;
	}
    if((*Head)->rptr == NULL && (*Head)->lptr == NULL){
        printf("%d is removed\n",(*Head)->value);
        free(*Head);
        *Head = *Rear = NULL;
        return;
    }
	delete = *Head;
	*Head = (*Head)->rptr;
	(*Head)->lptr = *Rear;
    (*Rear)->rptr = *Head;
    printf("%d is removed\n",delete->value);
	free(delete);
}

void del_end(struct Node** Head,struct Node** Rear){
	struct Node * delete;

	if(*Head == NULL){
		printf("The list is Empty\n");
		return;
	}
    if(*Head == *Rear){
        printf("%d is removed\n",(*Head)->value);
        free(*Head);
        *Head = *Rear = NULL;
        return;
    }

    delete = *Rear;
	(*Rear) = (*Rear)->lptr;
	(*Rear)->rptr = *Head;
    (*Head)->lptr = *Rear;
    printf("%d is removed\n",delete->value);
	free(delete);
}

void del_specific(struct Node** Head,struct Node** Rear,int val){
	struct Node * temp;
	temp = *Head;

	if(*Head == NULL){
		printf("The list is Empty\n");
		return;
	}

	if( val == (*Head)->value){
        if(*Head == *Rear){         //condition for only Node
            printf("%d is removed\n",(*Head)->value);
            free(*Head);
            *Head = *Rear = NULL;
        }
        else{
            temp = *Head;
            *Head = (*Head)->rptr;
            (*Head)->lptr = *Rear;
            (*Rear)->rptr = *Head;
            printf("%d is removed\n",temp->value);
            free(temp);
        }
	}
	else if(val == (*Rear)->value){

		temp = *Rear;
		(*Rear) = (*Rear)->lptr;
		(*Rear)->rptr = *Head;
        (*Head)->lptr = *Rear;
        printf("%d is removed\n",temp->value);
		free(temp);
	}
	else{
		while (temp != NULL && temp->value != val)
			temp = temp->rptr;

		if(temp == NULL){
			printf("Value is not found\n");
			return;
		}
		//temp points to the node to be deleted

		temp->lptr->rptr = temp->rptr;
		temp->rptr->lptr = temp->lptr;
        printf("%d is removed\n",temp->value);
		free(temp);
	}
}

void display(struct Node * H){
    struct Node *temp;
    temp = H;

    if(temp == NULL){
        printf("List is empty\n");
        return;
    }

	printf("The Numbers in list is..");
    do{
        printf("%d ",temp->value);
        temp = temp->rptr;
    }while(temp!= H);
    printf("\n");

}


int main(){
    struct Node* Head;
    struct Node* Rear;
    Head = Rear = NULL;
    int val,n,sval;

    printf("1 for insert value at front:\n");
    printf("2 for insert value at rear:\n");
    printf("3 for insert value according to order:\n");
    printf("4 for insert value after specific value:\n");
    printf("5 for delete from front\n");
	printf("6 for delete from end\n");
	printf("7 for delete specific value\n");
    printf("8 for display\n");
	printf("9 for Exit\n");
    scanf("%d",&n);

    while(n !=9){

        switch(n){
        case 1:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_front(&Head,&Rear,val);
            break;
        case 2:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_rear(&Head,&Rear,val);
            break;
        case 3:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_order(&Head,&Rear,val);
            break;
        case 4:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_specs(&Head,&Rear,val);
            break;
		case 5:
			del_front(&Head,&Rear);
			break;
		case 6:
			del_end(&Head,&Rear);
			break;
		case 7:
			printf("Enter value you want to be deleted\n");
			scanf("%d",&val);
			del_specific(&Head,&Rear,val);
			break;
        case 8:
            display(Head);
            break;
        default:
            printf("Enter specific value:\n");
        }

        printf("Enter which type of the operation you want to apply:\n");
        scanf("%d",&n);
    }
    return 0;
}
