class Solution {
public:

    void deletenode(TreeNode*& root, int target) {
        if (root == NULL) return;

        // process children first (postorder)
        deletenode(root->left, target);
        deletenode(root->right, target);

        // if current node is a target leaf
        if (root->left == NULL && root->right == NULL && root->val == target) {
            
            root = NULL;   // IMPORTANT: updates parent's pointer
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        deletenode(root, target);
        return root;
    }
};