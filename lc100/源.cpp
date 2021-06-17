/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)

    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
class Solution {
public:
    bool _isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        if ((p != nullptr && q == nullptr) || (q != nullptr && p == nullptr) || p->val != q->val)
        {
            return false;
        }
        return _isSameTree(p->left, q->left) && _isSameTree(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {

        TreeNode* curleft = p;
        TreeNode* curright = q;
        return _isSameTree(curleft, curright);

    }
};