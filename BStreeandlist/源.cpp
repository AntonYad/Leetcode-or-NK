class Solution {
public:
    void _Convert(TreeNode* root, TreeNode*& prev)
    {
        if (root == nullptr)
        {
            return;
        }
        _Convert(root->left, prev);
        root->left = prev;
        if (prev)
        {
            prev->right = root;
        }
        prev = root;
        _Convert(root->right, prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }
        TreeNode* prev = nullptr;
        TreeNode* cur = pRootOfTree;
        _Convert(cur, prev);
        TreeNode* head = pRootOfTree;
        while (head->left)
        {
            head = head->left;
        }
        return head;
    }
};