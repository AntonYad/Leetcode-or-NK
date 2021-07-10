class Solution {
public:
    vector<int> res;
    void _getMinimumDifference(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        _getMinimumDifference(root->left);
        res.push_back(root->val);
        _getMinimumDifference(root->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        _getMinimumDifference(root);
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] - res[i - 1] < min)
            {
                min = res[i] - res[i - 1];
            }
        }
        return min;
    }
};