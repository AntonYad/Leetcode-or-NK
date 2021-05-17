class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* prev = nullptr;
		stack<TreeNode*> st;
		vector<int> v;
		if (cur == nullptr)
		{
			return v;
		}
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			TreeNode* top = st.top();
			if (top->right == nullptr || top->right == prev)
			{
				v.push_back(top->val);
				st.pop();
				prev = top;
			}
			else
			{
				cur = top->right;
			}

		}
		return v;
	}
};