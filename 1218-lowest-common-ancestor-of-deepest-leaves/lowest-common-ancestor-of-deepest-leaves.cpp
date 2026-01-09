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
        if(root==NULL)return 0 ;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1 ;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         int left  = height(root->left);
        int right = height(root->right);
        if(left==right)return root ;
        TreeNode* Node;
        if(left>right){
           Node =lcaDeepestLeaves(root->left);
        }else{
           Node =lcaDeepestLeaves(root->right);
        }
        return Node ;
        
    }
};