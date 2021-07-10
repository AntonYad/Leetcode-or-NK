class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            TreeNode* newnode = new TreeNode(val);
            root = newnode;
            return root;
        }
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur)
        {
            if (cur->val > val)
            {
                prev = cur;
                cur = cur->left;
            }
            else
            {
                prev = cur;
                cur = cur->right;
            }
        }
        TreeNode* newnode = new TreeNode(val);
        if (prev->val > val)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
        return root;

    }
};