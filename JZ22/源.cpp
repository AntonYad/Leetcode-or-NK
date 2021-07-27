class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if (root == nullptr)
        {
            return v;
        }
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return v;

    }
};