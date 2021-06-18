class Solution {
public:
    void _inorderTraversal(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr)
        {
            return;
        }
        _inorderTraversal(root->left, v);
        v.push_back(root->val);
        _inorderTraversal(root->right, v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        _inorderTraversal(root, v);
        return v;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode* p = s.top();
            s.pop();
            v.push_back(p->val);

            cur = p->right;
        }
        return v;

    }
};


