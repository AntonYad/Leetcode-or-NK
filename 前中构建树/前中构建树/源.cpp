class Solution {
public:

	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int begin, int end)
	{
		if (previ == preorder.size())
		{
			return nullptr;
		}
		if (begin>end)
		{
			return nullptr;
		}
		int rooti = begin;
		while (rooti <= end)
		{
			if (preorder[previ] == inorder[rooti])
			{
				break;
			}
			else
			{
				rooti++;
			}
		}
		TreeNode* root = new TreeNode(preorder[previ]);
		++previ;
		root->left = _buildTree(preorder, inorder, previ, begin, rooti - 1);
		root->right = _buildTree(preorder, inorder, previ, rooti + 1, end);

		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int previ = 0;
		return _buildTree(preorder, inorder, previ, 0, inorder.size() - 1);
	}
};