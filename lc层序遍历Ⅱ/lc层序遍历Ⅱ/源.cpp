class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == nullptr)
		{
			return vv;
		}
		TreeNode* cur = root;
		queue<TreeNode*> q;
		q.push(cur);
		while (q.size())
		{
			int len = q.size();
			vector<int> v;
			while (len--)
			{
				TreeNode* front = q.front();
				q.pop();
				v.push_back(front->val);
				if (front->left)
				{
					q.push(front->left);
				}
				if (front->right)
				{
					q.push(front->right);
				}
			}
			vv.push_back(v);
		}
		reverse(vv.begin(), vv.end());
		return vv;

	}
};