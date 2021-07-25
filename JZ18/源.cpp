class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return TreeNode类
     */

    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (pRoot == nullptr)
        {
            return nullptr;
        }
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};