/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
  stack<TreeNode*> s;

  BSTIterator(TreeNode *root) {
      if(root) s.push(root);
      while(root&&root->left){
          s.push(root->left);
          root=root->left;
      }

  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
      return !s.empty();
  }

  /** @return the next smallest number */
  int next() {
      TreeNode* top = s.top();
      int ans = top->val;
      s.pop();
      if(top->right){
          s.push(top->right);
          top=top->right;
          while(top->left){
              s.push(top->left);
              top=top->left;
          }
      }
      return ans;
  }

};


/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
