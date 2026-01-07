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
    long long mx = 0 ;
    static const int  MOD =1e9+7;
    long long totalsumofTree(TreeNode* root){
        if(root==NULL)return 0;
       return  root->val+totalsumofTree(root->left)+totalsumofTree(root->right);
      
    }
    long long recursion(TreeNode* root,long long &total){
        
        if(root == NULL)return 0 ;
     
        long long left = recursion(root->left,total);
        long long right = recursion(root->right,total);
        long long subsum  = root->val+left+right;
        mx = max(mx,subsum*(total-subsum));
        cout<<mx<<endl;
        return subsum ;
    }
    int maxProduct(TreeNode* root) {
        long long total = totalsumofTree(root); 
        recursion(root,total);
        return mx%MOD;
        
    }
};