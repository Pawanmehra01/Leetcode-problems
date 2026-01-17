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
    TreeNode* ansNode(vector<int>&nums,int i,int end){
        if(i>end)return NULL;
        int mid = (i+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left=ansNode(nums,i,mid-1);
        root->right= ansNode(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        int end = nums.size()-1;
        return ansNode(nums,0,end);
    
        
    }
};