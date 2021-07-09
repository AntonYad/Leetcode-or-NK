class Solution {
public:
    bool _hasPathSum(TreeNode* root, int count)
    {
        if (root->left == nullptr && root->right == nullptr && count == 0)
        {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return false;
        }
        if (root->left)
        {
            count -= root->left->val;
            if (_hasPathSum(root->left, count))
            {
                return true;
            }
            count += root->left->val;
        }
        if (root->right)
        {
            count -= root->right->val;
            if (_hasPathSum(root->right, count))
            {
                return true;
            }
            count += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
        {
            return false;
        }
        return _hasPathSum(root, targetSum - root->val);

    }
};