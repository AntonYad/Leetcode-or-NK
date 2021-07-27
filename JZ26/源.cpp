class Solution {
public:
    void tree(TreeNode* root, TreeNode*& prev)
    {
        if (root == nullptr)
        {
            return;
        }
        tree(root->left, prev);
        root->left = prev;
        if (prev)
        {
            prev->right = root;
        }
        prev = root;
        tree(root->right, prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }
        TreeNode* prev = nullptr;
        tree(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        while (head->left)
        {
            head = head->left;
        }
        return head;
    }
};