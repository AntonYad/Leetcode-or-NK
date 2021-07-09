class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int count = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            count += root->left->val;
        }
        return count + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};