#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node{
    char data;
    bool end;
    node* children[26];
    
    node(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    
    node(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
    
    friend ostream& operator<<(ostream& os, const node& n){
        os<<n.data<<" "<<(n.end?"true":"false")<<" [ ";
        for(int i=0;i<26;i++){
            if(n.children[i]!=NULL){
                os<<char(i+'a')<<", ";
            }
        }
        os<<"\b ]"<<endl;
        return os;
    }
};

class Trie{
    private:
        node* root;
        static void dfs(node* root, string prefix, vector<string> *words){
            if(root->end){
                words->push_back(prefix);
            }
            
            for(char c='a'; c<='z'; c++){
                if(root->children[c-'a']!=NULL){
                    dfs(root->children[c-'a'], prefix+c, words);
                }
            }
        }
        
    public:
        Trie(){
            this->root = new node();
        }
        
        void add(string word){
            node* temp = this->root;
            for(char c:word){
                if(temp->children[c-'a']==NULL){
                    temp->children[c-'a'] = new node(c);
                }
                temp = temp->children[c-'a'];
            }
            temp->end=true;
        }
        
        bool find(string word){
            node* temp = this->root;
            for(char c:word){
                if(temp==NULL){
                    return false;
                }
                temp = temp->children[c-'a'];
            }
            if(temp==NULL){
                return false;
            }
            return temp->end;
        }
        
        void lookup_node(string word){
            node* temp = this->root;
            for(char c:word){
                if(temp==NULL){
                    return;
                }
                temp = temp->children[c-'a'];
            }
            if(temp==NULL){
                return;
            }
            cout<<*temp;
        }
        
        vector<string> search(string prefix){
            node* temp = this->root;
            vector<string> results;
            for(char c:prefix){
                if(temp->children[c-'a']==NULL){
                    return results;
                }
                temp=temp->children[c-'a'];
            }
            if(temp==NULL){
                return results;
            }
            dfs(temp, prefix, &results);
            return results;
        }
};

int main(void){
    Trie t;
    
    t.add("abc");
    t.add("abcdef");
    t.add("def");
    for(auto w:t.search("ab")){
        cout<<w<<endl;
    }
    
    return 0;
}