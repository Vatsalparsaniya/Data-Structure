#include<stdio.h>
int top=-1,top2=-1;
int MAXSIZE=100;
char s[100];

int isOperand(char x){
	if((x>='a'&& x<='z')||(x>='A' && x<='Z')){
		return 1;
	}
	else
		return 0;
}

void push(char x){

	s[++top]=x;

}

char pop(){

	return s[top--];

}

int priority(char x){
	if(x=='('){
		return 0;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
}

int main(){
    int p=0;
	char exp[MAXSIZE],*e,postfix[MAXSIZE];
	printf("Enter your infix Expression : ");
	scanf("%s",exp);
	e=exp;
	printf(" your Postfix Expression is : ");
	while(*e!='\0'){

		if(isOperand(*e)){
                postfix[p]=*e;
			printf("%c",postfix[p++]);

		}

		else if(*e=='('){
			push(*e);
		}

		else if(*e==')'){
			while(s[top]!='('){
                postfix[p]=pop();
				printf("%c",postfix[p++]);


			}
			top--;
		}

		else{
			while(priority(s[top])>=priority(*e)){
                    postfix[p]=pop();
					printf("%c",postfix[p++]);


			}
			push(*e);
		}
	e++;
	}

    while(top!=-1){
        postfix[p]=pop();
        printf("%c",postfix[p++]);
    }
    printf("\n");
    return 0;
}

