#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
    string s;cin>>s;
    stack <char>st;
    bool f=true;
    for(int i=0;i<s.length();i++){

        if(s[i]!=')')   st.push(s[i]);
        else{
        if(st.top()=='(')  f=false;
        while(st.top()!='(')  st.pop();st.pop();
        }
    }
    if(f)  cout<<"No Duplicates Found ";
    else cout<<"Duplicate Found ";
    cout<<endl;
}
}
