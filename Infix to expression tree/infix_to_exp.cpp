#include<iostream>
#include<stack>
using namespace std;
struct node{
char data;
struct node  *right,*left;
};
class infix
{
    string result = "";
    stack<char> s ;
    public: string decode(string exp)
    {
        for(int i=0;i<exp.size();i++)
        {
            if(isoperand(exp[i]))
            {
                result = result+exp[i];
            }
            else if(isoperator(exp[i]))
            {
                while(!s.empty() && s.top()!='(' && hashigherprecedence(s.top(),exp[i]))
                 {
                     result = result+s.top();
                     s.pop();
                 }
                 s.push(exp[i]);
            }
            else if(exp[i]=='(')
            {
                s.push(exp[i]);
            }
            else if(exp[i]==')')
            {
                while(!s.empty() && s.top()!='(')
                {
                    result = result+s.top();
                    s.pop();
                }
                s.pop();
            }
        
        }
            while(!s.empty())
            {
                result = result+s.top();
                s.pop();
            }
        return result;
    }
    bool isoperand(char s)
    {
        if((s<=9 && s>=0)||(s<='Z' && s>='A')||(s<='z' && s>='a'))
        return true;
        else return false;

    }
    bool isoperator(char x)
    {
      if(x=='+'||x=='-'||x=='/'||x=='*'||x=='^')
      return true;
      else return false;
    }
    int getweight(char m)
    {
        int weight =-1;
        switch(m)
        {
            case '+':
            case '-':
            weight = 1;
            break;
            case '*':
            case '/':
            weight = 2;
            case '^':
            weight = 3;
        }
        return weight;
    }
    bool isrightassociative(char a)
    {
      if(a=='^')return true;
      else return false;
    }
    bool hashigherprecedence(char a, char b)
    {
       int weight1 = getweight(a);
       int weight2 = getweight(b);
       if(weight1==weight2)
       {
       if(isrightassociative(a))
       return false;
       else 
       return true;
       }
       return weight1 > weight2 ? true : false;

    }
node* expressiontree(string postfix)

{
 stack <node*> s; 
int size = postfix.size();
for(int i=0;i<size;i++)
{
    if(isoperand(postfix[i]))
    {
        node* temp = (node*)malloc(sizeof(node));
        if(temp==NULL)
        {
            return NULL;
        }
        temp->data= postfix[i];
        temp->left = NULL;
        temp->right = NULL;
        s.push(temp);


    }
    else
    {
        node* t2 = s.top();
        s.pop();
        node* t1 = s.top();
        s.pop();
        node* temp = (node*)malloc(sizeof(node));
        if(temp==NULL)
        {
            cout<<"memory error"<<endl;
            return NULL;
        }
        temp->data = postfix[i];
        temp->left = t1;
        temp->right = t2;
        s.push(temp);

    }
    
}
return s.top();
}
};
int main()
{
    infix t;
    node* x = t.expressiontree(t.decode("(a+n)*(c+d)"));
    return 0;
}