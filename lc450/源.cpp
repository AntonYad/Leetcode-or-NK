class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                return root->right;
            }
            else if (root->right == nullptr)
            {
                return root->left;
            }
            else
            {
                TreeNode* cur = root->right;
                while (cur->left)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* denode = root;
                root = root->right;
                delete denode;
                return root;
            }
        }
        if (root->val > key) { root->left = deleteNode(root->left, key); }
        if (root->val < key) { root->right = deleteNode(root->right, key); }
        return root;

    }
};