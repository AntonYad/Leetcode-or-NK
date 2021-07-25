class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pRoot TreeNode��
     * @return TreeNode��
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