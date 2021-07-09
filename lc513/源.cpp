class Solution {
public:
    int maxlen = INT_MIN;
    int leftnum;
    void _findBottomLeftValue(TreeNode* root, int len)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            if (len > maxlen)
            {
                leftnum = root->val;
                maxlen = len;
            }
        }
        if (root->left)
        {
            _findBottomLeftValue(root->left, len + 1);
        }
        if (root->right)
        {
            _findBottomLeftValue(root->right, len + 1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int len = 0;
        _findBottomLeftValue(root, len);
        return leftnum;
    }
};