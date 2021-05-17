class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> q;
		TreeNode* cur = root;
		if (cur == nullptr)
		{
			return v;
		}
		while (cur || !q.empty())
		{
			while (cur)
			{
				v.push_back(cur->val);
				q.push(cur);
				cur = cur->left;
			}

			TreeNode* top = q.top();
			q.pop();

			cur = top->right;
		}
		return v;
	}
};