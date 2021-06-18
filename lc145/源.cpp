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




