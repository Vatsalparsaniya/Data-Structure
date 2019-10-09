/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* findPred(TreeNode* current){
    TreeNode* temp=current;
    temp=temp->left;
    while(temp->right!=NULL&&temp->right!=current){
        temp=temp->right;
    }
    return temp;
} 
 
vector<int> MorrisTraversal(TreeNode* root){
    vector<int> ans;
    TreeNode* current = root;
    while(current!=NULL){
        if(!current->left){
//            cout<<current->val<<" ";
            ans.push_back(current->val);
            current = current->right;
        }else{
            TreeNode* predecessor = findPred(current);
            if(!predecessor->right){
                predecessor->right = current;
                current = current ->left;
            }else{
                predecessor->right = NULL;
//                cout<<current->val<<" ";
                ans.push_back(current->val);
                current=current->right;;
            }
        }
    }
    return ans;
} 

vector<int> inorderTraversal(TreeNode* A) {

    return MorrisTraversal(A);

}
