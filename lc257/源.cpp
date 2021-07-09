class Solution {
public:
    void _binaryTreePaths(TreeNode* root, vector<string>& res, vector<int>& paths)
    {
        paths.push_back(root->val);
        if (!root->left && !root->right)
        {
            string s;
            for (int i = 0; i < paths.size() - 1; i++)
            {
                s += to_string(paths[i]);
                s += "->";
            }
            s += to_string(paths[paths.size() - 1]);
            res.push_back(s);
            return;
        }
        if (root->left)
        {
            _binaryTreePaths(root->left, res, paths);
            paths.pop_back();
        }
        if (root->right)
        {
            _binaryTreePaths(root->right, res, paths);
            paths.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> paths;
        if (root == nullptr)
        {
            return res;
        }
        _binaryTreePaths(root, res, paths);
        return res;
    }
};