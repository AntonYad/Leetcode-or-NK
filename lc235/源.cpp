class Solution {
public:
    bool _lowestCommonAncestor(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == NULL)
        {
            return false;
        }
        path.push(root);
        if (root == x)
        {
            return true;
        }
        if (_lowestCommonAncestor(root->left, x, path))
        {
            return true;
        }
        if (_lowestCommonAncestor(root->right, x, path))
        {
            return true;
        }
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root)
        {
            return root;
        }
        stack<TreeNode*> pathp;
        stack<TreeNode*> pathq;
        _lowestCommonAncestor(root, p, pathp);
        _lowestCommonAncestor(root, q, pathq);
        while (pathp.size() > pathq.size())
        {
            pathp.pop();
        }
        while (pathq.size() > pathp.size())
        {
            pathq.pop();
        }
        while (pathp != pathq)
        {
            pathp.pop();
            pathq.pop();
        }
        return pathq.top();
    }
};