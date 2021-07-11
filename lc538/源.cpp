class Solution {
public:
    int prev;
    void _convertBST(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        _convertBST(root->right);
        root->val += prev;
        prev = root->val;
        _convertBST(root->left);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        int prev = 0;
        _convertBST(root);

        return root;

    }
};