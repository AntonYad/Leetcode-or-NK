class Solution {
public:
    void _preorderTraversal(TreeNode* root, vector<int>& v)
    {
        if (root == nullptr)
        {
            return;
        }
        v.push_back(root->val);
        _preorderTraversal(root->left, v);
        _preorderTraversal(root->right, v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        TreeNode* cur = root;

        _preorderTraversal(cur, v);
        return v;

    }
};



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        TreeNode* cur = root;
        stack<TreeNode*> q;
        while (cur || !q.empty())
        {
            while (cur)
            {
                v.push_back(cur->val);
                q.push(cur);
                cur = cur->left;
            }
            TreeNode* p = q.top();
            q.pop();

            cur = p->right;
        }
        return v;
    }
};