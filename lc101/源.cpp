class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();

            if (left != nullptr && right == nullptr)
            {
                return false;
            }
            else if (left == nullptr && right != nullptr)
            {
                return false;
            }
            else if (left == nullptr && right == nullptr)
            {
                continue;
            }
            else if (left->val != right->val)
            {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};