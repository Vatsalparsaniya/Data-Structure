#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
          this->data=data;
          this->left=NULL;
          this->right=NULL;
       }
};
node* root;
class BinarySearchTree{
    public:
        void insert(node* root,int* a,int i){
            if(root==NULL){
                return;
            }

            if(a[i]<root->data){
                if(root->left==NULL){
                    node*nn=new node(a[i]);
                    root->left=nn;

                }
                else{
                    insert(root->left,a,i);
                }
            }
            else{
                if(root->right==NULL){
                    node*nn=new node(a[i]);
                    root->right=nn;


                }
                else{
                    insert(root->right,a,i);
                }
            }
        }

        void FindMax(node* root,node* max){
            if(root!=NULL){
                if(root->data > max->data){
                   max=root;

                }
                FindMax(root->right,max);
            }


        }

        void del(node* root,int val){
        if(root==NULL){
                return;
            }
           if(root->left==NULL && root->right==NULL){
            cout<<root->data<<endl;
            cout<<val<<endl;
                root=NULL;
                return;
            }

            if(val==root->data){
                node* max=root->left;
                FindMax(root->left,max);
                root->data=max->data;
                if(max->left==NULL && max->right==NULL){
                   root->left=root->left->left;
                   return;
                }
                del(max,max->data);
                return;
            }
            if(val<root->data){
                del(root->left,val);
            }
            else{
                del(root->right,val);
            }
        }
        void preOrder(node* root){
            if(root!=NULL){
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);
        }
        }
        void postOrder(node* root){
            if(root!=NULL){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
        }
        void inOrder(node*root){
            if(root!=NULL){
            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }
        }

};
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* nn=new node(arr[0]);
    root=nn;
    BinarySearchTree bst;
    for(int i=1;i<n;i++){
      bst.insert(root,arr,i);
    }
    bst.preOrder(root);
    int val;
    cin>>val;
    bst.del(root,val);
    bst.preOrder(root);
}

