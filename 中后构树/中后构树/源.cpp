class Solution {
public:
	TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& previ, int begin, int end)
	{
		if (previ<0)
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
			if (postorder[previ] == inorder[rooti])
			{
				break;
			}
			rooti++;
		}
		TreeNode* root = new TreeNode(postorder[previ]);
		previ--;

		root->right = _buildTree(inorder, postorder, previ, rooti + 1, end);
		root->left = _buildTree(inorder, postorder, previ, begin, rooti - 1);

		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int previ = postorder.size() - 1;
		return _buildTree(inorder, postorder, previ, 0, inorder.size() - 1);
	}
};