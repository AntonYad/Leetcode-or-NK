class Solution {
public:
	void _Convert(TreeNode* cur, TreeNode*& prev)
	{
		if (cur == nullptr)
		{
			return;
		}

		_Convert(cur->left, prev);
		cur->left = prev;
		if (prev)
		{
			prev->right = cur;
		}
		prev = cur;
		_Convert(cur->right, prev);
	}
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr)
		{
			return pRootOfTree;
		}
		TreeNode* prev = nullptr;
		_Convert(pRootOfTree, prev);
		TreeNode* head = pRootOfTree;
		while (head->left)
		{
			head = head->left;
		}
		return head;
	}
};