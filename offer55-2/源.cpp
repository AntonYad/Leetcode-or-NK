class Solution {
public:
    int dm(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(dm(root->left), dm(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        int ld = dm(root->left);
        int rd = dm(root->right);
        return abs(ld - rd) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};