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
    vector<int>sortedArr;
    TreeNode* buildbst(int i , int n ){
        if(i>n){
            return NULL;
        }
        int mid =(i+n)/2;
        TreeNode* node = new TreeNode(sortedArr[mid]);
        node->left = buildbst(i,mid-1) ;
        node->right =buildbst(mid+1,n);
        return node;
    }
    void inorder(TreeNode* root){
        if(root==NULL)return ;
        inorder(root->left);
        sortedArr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {

        inorder(root);
        int i = 0 ;
        int n = sortedArr.size()-1;
        return buildbst(i,n);

    }
};