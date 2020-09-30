#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 40
typedef struct{
	char ele[MAX];
	int top;
}stack;
void reverse(char ex[]);
void infixtopost(char exp[],stack s);
int check(char exp[],stack s);
void infixtoprefix(char exp[],stack s);

char pop(stack *s);
void push(stack *s,char item);
char peek(stack s);
int isEmpty(stack *s);
int isFull(stack *s);
void deletion(stack s);
void display(stack s);
int prec2(char ch);
int prec1(char ch);
void reverse(char exp[],stack s);
char post[MAX];
int main(){
	stack s;
	s.top=-1;
	do{ 
		int ch;
		char exp[MAX];
		
		printf("\n\nMenue\n\n\nEnter 1 for infix to postfix\n\n\nEnter 2 for infix to prefix\n");
		printf("\n\nEnter your choice\n\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			printf("\nEnter the expression to be evaluated\n");
			scanf("%s",exp);
				if(check(exp,s))
				
			    infixtopost(exp,s); 
			    else{
				printf("\n\nThe entered expression is invalid enter some valid expression\n\n");
			}
		       
			break;
			
			case 2:
					printf("\nEnter the expression to be evaluated\n");
			        scanf("\n%s",exp);
				if(check(exp,s)){
				
				infixtoprefix(exp,s);
			     
			       }
			else{
				printf("\n\nThe entered expression is invalid enter some valid expression\n\n");
			}
			break;
			case 3: 
				printf("\n\nBye!Bye you exit\n\n");
				exit(0);
				
			default:
				printf("\n\nWrong Choice\n\n");
				
		}
	}while(1);
}
int check(char exp[],stack s){
    
	int i,k;
	k=strlen(exp);
		for(i=0;exp[i]!='\0';i++)
	{
		
		if(exp[i]=='(')
		push(&s,exp[i]);
		else if(exp[i]==')')
		{
			if(s.top==-1)
				break;
			else
				pop(&s);
		}
		
   }
	if(s.top==-1&& i==k)
	return 1;
	else
	return 0;

	   
	}
	
void reverse(char ex[]){
   	int i,n,end;
   	char temp;
   	n=strlen(ex);
    end=n-1;
 	for(i=0;i<n/2;i++){
 		 temp=ex[i];
		 ex[i]=ex[end];
		 ex[end]=temp;
		 end--;
	 }
	 for(i=0;i<n;i++){
	 
	 if(ex[i]=='(')
	 {
	 	ex[i]=')';
	 }
	 else if(ex[i]==')'){
	 	ex[i]='(';
	 }
	}
	ex[i]='\0';

}
void infixtopost(char exp[],stack s)
{   
int i,k;
	for(i=0,k=0;exp[i]!='\0';i++)
	{
		if(isalpha(exp[i]))
			post[k++]=exp[i];
			
		
		else if(exp[i]=='(')
		{
			push(&s,exp[i]);
			
		}
			
		else if(exp[i]==')')
		{
			while(!isEmpty(&s)&&peek(s)!='('){
		post[k++]=pop(&s);	
			}
			 
                pop(&s); 
        }
    
		else{
			while(!isEmpty(&s)&&(prec2(exp[i])<=prec1(peek(s))))
			
				post[k++]=pop(&s);
			
			push(&s,exp[i]);
			
		}
	}
		while(!isEmpty(&s)){
			post[k++]=pop(&s);
		}
			post[k]='\0';
		 printf("%s\n",post);
		}
		
		
		int prec1(char ch)
		{
			switch(ch){
			
			case '+':
			case '-':
				return 1;
				break;
			case '/':
			case '*':
			case '%':
				return 2;
				break;
			case '^':
				return 3;
			    break;
		    default:
				return 0;
			    
	}
}
	int prec2(char ch){
		switch(ch){
		
			case '+':
			case '-':
				return 1;
				break;
			case '/':
			case '*':
			case '%':
				return 2;
				break;
			case '^':
				return 4;
			    break;
			default:
				return 0;
	}
				
			
   }
   void infixtoprefix(char exp[],stack s){
   	reverse(exp);
   	
   	infixtopost(exp,s);
   	
   	reverse(post);
   	puts(post);
    
   }
   

   
   
   void push(stack *s,char item){
	if(isFull(s)){
	printf("\nStack overflow......\n");	
	}
	else{
		s->top++;
		s->ele[s->top]=item;
		
	}
}
char pop(stack *s){
	char item;
	if(isEmpty(s)){
	printf("\nStack Underflow......\n");
	return -1;
		
	}
	else{
	item=s->ele[s->top];
	s->top--;
	return item;
	}
}
char peek(stack s){
	char item;
	if(isEmpty(&s)){
		printf("\nStack nderflow\n");
		return -1;
	}
	else
	{
		item=s.ele[s.top];
		return item;
	}
	}
	
int isEmpty(stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(stack *s)
{
	if(s->top==MAX)
	{
		return 1;
	}
	else{
		return 0;
	}
}



	   
	
