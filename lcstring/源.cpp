class Solution {
public:
    string tree2str(TreeNode* root) {
        TreeNode* cur = root;
        string str = "";
        if (cur == nullptr)
        {
            return str;
        }
        str += to_string(root->val);
        if (!root->right && !root->left)
        {
            return str;
        }

        str += '(';
        str += tree2str(root->left);
        str += ')';

        if (root->right)
        {
            str += '(';
            str += tree2str(root->right);
            str += ')';
        }
        return str;
    }
};