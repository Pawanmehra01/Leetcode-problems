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
    int binarytonumber(string s){
        int sum = 0 ;
        int two = 1 ;
        for(int i = s.length()-1; i>=0;i--){
            char c = s[i];
            int j = c - '0';
            sum = sum + (two*j) ;
            two = two*2 ;
        }
        return sum ;
    }
    int solve(TreeNode* root , string w){
        if(root==NULL)return 0 ; 

        w = w + to_string(root->val);

        if(root->left == NULL && root->right == NULL ){
           int ans = binarytonumber(w);
           return ans;
        }
        
        int left  =  solve(root->left,w);
        int right  = solve(root->right,w) ;
        return left + right ;

        
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)return 0 ;
        return solve(root,"") ;
        
    }
};