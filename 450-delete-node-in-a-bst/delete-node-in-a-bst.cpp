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
        TreeNode* findMin(TreeNode* root ){
            while(root->left!=NULL){
                root = root->left;
            }
            return root ;

        }
        void deleteit(TreeNode* &root ,int key ){
            if(root->left == NULL && root->right == NULL ){
                delete root ;
                root = NULL ;
                
            }
            else if (root->right!=NULL &&  root->left==NULL ){
                TreeNode* temp = root ;
                root = root->right ;
                delete temp ;
            }
            else if(root ->right == NULL  && root->left!=NULL){
                TreeNode* temp = root ;
                root = root->left ;
                delete temp ;
                
            }
            else if(root->right!=NULL && root->left != NULL){
                TreeNode* minval = findMin(root->right);
                root->val = minval->val;
                search(root->right,minval->val) ;
            }

        }
        void search(TreeNode* &root ,int key ){
        if(root==NULL)return ;

        if(root->val == key){

            deleteit(root,key);
        }
        else if(root -> val < key){
            search(root->right,key);
        }else {
            search(root->left,key); 
        }
      
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      
        search(root,key);
        return root ;

    }
};