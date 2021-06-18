class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }
        return hasSubStructure(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);

    }
    bool hasSubStructure(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        }
        if (A == nullptr) {
            return false;//在不满足b为nullptr但是A变成了空
        }
        if (A->val != B->val) {
            return false;
        }
        return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right);
    }
};