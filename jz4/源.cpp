class Solution {
public:
    TreeNode* use(vector<int> pre, vector<int> vin, int& previ, int begin, int end)
    {
        if (previ == pre.size())
        {
            return nullptr;
        }
        if (begin > end)
        {
            return nullptr;
        }
        int rooti = begin;
        while (rooti <= end)
        {
            if (vin[rooti] == pre[previ])
            {
                break;
            }
            rooti++;
        }
        TreeNode* root = new TreeNode(pre[previ]);
        previ++;
        root->left = use(pre, vin, previ, begin, rooti - 1);
        root->right = use(pre, vin, previ, rooti + 1, end);

        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int previ = 0;
        return use(pre, vin, previ, 0, vin.size() - 1);
    }
};