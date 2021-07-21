class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    // ����Ϊ2�����飬0����͵��1��͵
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // ͵cur
        int val1 = cur->val + left[0] + right[0];
        // ��͵cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { val2, val1 };
    }
};