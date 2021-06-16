class Solution {
public:
    bool _isUnivalTree(TreeNode* root, int val)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val != val)
        {
            return false;
        }
        return _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
    }
    bool isUnivalTree(TreeNode* root)
    {
        int val = root->val;
        TreeNode* cur = root;
        return _isUnivalTree(root, val);
    }
};