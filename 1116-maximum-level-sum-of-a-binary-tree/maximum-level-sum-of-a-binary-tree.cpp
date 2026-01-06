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
    vector<int>allsum={INT_MIN};
    void recursion(TreeNode*root,int level){
        if(root==NULL)return ;
        if(allsum.size()==level)allsum.push_back(root->val);
        else{
            allsum[level]+=root->val ;
        }
        recursion(root->left,level+1);
        recursion(root->right,level+1);

    }
    int maxLevelSum(TreeNode* root) {
        recursion(root,1);
        return max_element(allsum.begin(),allsum.end())-allsum.begin();
        
    }
};