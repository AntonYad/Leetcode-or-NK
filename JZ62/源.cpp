class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* cur = pRoot;
        stack<TreeNode*> st;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            st.pop();
            k--;
            if (k == 0)
            {
                return top;
            }
            cur = top->right;


        }
        return cur;
    }
};