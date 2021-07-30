class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (root == nullptr)
        {
            return vv;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            vector<int> v;
            while (len--)
            {
                TreeNode* top = q.front();
                q.pop();
                v.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            vv.push_back(v);
        }
        for (int i = 0; i < vv.size(); i++)
        {
            if (i % 2 == 1)
            {
                reverse(vv[i].begin(), vv[i].end());
            }
        }
        return vv;

    }
};