class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }
        swap(root->right, root->left);
        invertTree(root->left);
        invertTree(root->right);
        return root;

    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }
        queue<TreeNode*> q;
        TreeNode* p = root;
        q.push(p);
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                swap(cur->left, cur->right);
                if (cur->left)
                {
                    q.push(cur->left);
                }
                if (cur->right)
                {
                    q.push(cur->right);
                }
            }
        }
        return root;
    }
};

