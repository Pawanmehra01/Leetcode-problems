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
    // void inorder(TreeNode* root , vector<int>&sorted){
    //     if(root == NULL )return ;

    //     inorder(root->left ,sorted);
    //     sorted.push_back(root->val);
    //     inorder(root->right,sorted);
    // }
    void tree(TreeNode* &root ,int x) {
        if(root==NULL){
           root = new TreeNode(x);
           
           return ;
        }
        if(root->val < x ){
           tree(root->right, x) ;
        }else{
            tree(root->left , x) ;
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // vector<int>sorted ;
        // inorder(root,sorted );
        // sorted.push_back(val);
        // sort(sorted.begin(),sorted.end());
        
       
        if(root==NULL){
           TreeNode* node = new TreeNode(val);
           root = node ;
           return root ;
        }
        TreeNode*  ans = root ;
        tree(ans,val) ;
        return ans;   
    }
};