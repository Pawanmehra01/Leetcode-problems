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
    bool solve(TreeNode* leftside ,TreeNode* rightside){

        if(leftside==NULL && rightside==NULL)return true ;

        if(leftside==NULL ||  rightside==NULL)return false;
        //moved to the left most and rightmost node and then reverse checking  
        bool a1 = solve(leftside->left ,rightside->right) ;
        // reverse checking the node as moved to left and right ,
        // now we havbe  to check the  right node of the leftside and left node of the rightside
        bool a2 = solve(leftside->right ,rightside->left) ;

        bool ans = leftside->val == rightside->val ;

    return ans && a2 && a1 ;

    }
    bool isSymmetric(TreeNode* root) {
        
        return solve(root->left ,root->right); 
    }
};