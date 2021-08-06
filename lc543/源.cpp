class Solution {
public:
    int ans;
    int dfs(TreeNode* root) {
        if (!root)return 0;
        int l = dfs(root->left), r = dfs(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};