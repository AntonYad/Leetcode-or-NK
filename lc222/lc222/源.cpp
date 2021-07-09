class Solution {
public:
	void _countNodes(TreeNode* root, int& count)
	{
		if (root != nullptr)
		{
			count++;
		}
		if (root == nullptr)
		{
			return;
		}
		_countNodes(root->left, count);
		_countNodes(root->right, count);
	}
	int countNodes(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int count = 0;
		_countNodes(root, count);
		return count;
	}
};