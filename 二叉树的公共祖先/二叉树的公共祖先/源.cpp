class Solution {
public:
	bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
	{
		if (root == nullptr)
		{
			return false;
		}
		path.push(root);
		if (root == x)
		{
			return true;
		}
		if (FindPath(root->left, x, path))
		{
			return true;
		}
		if (FindPath(root->right, x, path))
		{
			return true;
		}
		path.pop();

		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		stack<TreeNode*> Path1;
		stack<TreeNode*> Path2;
		FindPath(root, p, Path1);
		FindPath(root, q, Path2);
		if (p == root || q == root)
		{
			return root;
		}
		while (Path1.size() > Path2.size())
		{
			Path1.pop();
		}
		while (Path1.size()<Path2.size())
		{
			Path2.pop();
		}
		while (Path1.top() != Path2.top())
		{
			Path1.pop();
			Path2.pop();
		}
		return Path1.top();


	}
};