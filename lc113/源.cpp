class Solution {
public:
    vector<vector<int>> pathsum;
    void _pathSum(TreeNode* root, vector<int>& path, int count)
    {
        if (root->left == nullptr && root->right == nullptr && count == 0)
        {
            pathsum.push_back(path);
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            _pathSum(root->left, path, count - root->left->val);

            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            _pathSum(root->right, path, count - root->right->val);

            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathsum.clear();
        vector<int> path;
        if (root == nullptr)
        {
            return pathsum;
        }
        int count;
        path.push_back(root->val);
        _pathSum(root, path, targetSum - root->val);
        return pathsum;
    }
};