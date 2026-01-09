/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0 ;
        int left  = height(root->left );
        int right = height(root->right);
        return 1+max(left,right);
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
          return root->val;
        int left  = height(root->left);
        int right = height(root->right);
        
        if(left>=right){
            return findBottomLeftValue(root->left);
        //  cout<<value<<endl;
        }
        else if(left<right){
            return  findBottomLeftValue(root->right);
        // cout<<value<<endl;
        }
      
        return root->val;
    }
};