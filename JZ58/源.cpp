class Solution {
public:
    bool is(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        return is(left->left, right->right) && is(left->right, right->left);
    }
    bool isSymmetrical(TreeNode* pRoot) {

        if (pRoot == nullptr)
        {
            return true;
        }
        return is(pRoot->left, pRoot->right);
    }

};