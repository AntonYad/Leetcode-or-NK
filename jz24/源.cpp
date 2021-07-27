class Solution {
public:
    void dfs(vector<vector<int>>& vv, vector<int> v, TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        v.push_back(root->val);
        if (sum < 0)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr && sum == root->val)
        {
            vv.push_back(v);
            return;
        }
        if (root->left)
            dfs(vv, v, root->left, sum - root->val);
        if (root->right)
            dfs(vv, v, root->right, sum - root->val);
        return;
    }
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int>> vv;
        vector<int> v;
        if (root == nullptr)
        {
            return vv;
        }
        if (root->val > expectNumber)
        {
            return vv;
        }

        dfs(vv, v, root, expectNumber);
        return vv;

    }
};