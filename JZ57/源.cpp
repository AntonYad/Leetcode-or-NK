class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* right = pNode->right;
        if (right)
        {
            while (right->left != nullptr)
            {
                right = right->left;
            }
            return right;
        }
        else
        {
            TreeLinkNode* parent = pNode->next;
            while (parent)
            {
                if (pNode == parent->left)
                {
                    return parent;
                }
                pNode = parent;
                parent = pNode->next;
            }
        }
        return nullptr;
    }
};