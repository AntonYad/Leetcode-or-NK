class Solution {
public:
    TreeNode* _constructMaximumBinaryTree(vector<int>& nums, int begin, int end, int& len)
    {
        if (len == -1)
        {
            return nullptr;
        }
        if (begin > end)
        {
            return nullptr;
        }
        int start = begin;
        int max = -1;
        int maxi;
        while (start <= end)
        {
            if (nums[start] > max)
            {
                max = nums[start];
                maxi = start;
            }
            start++;
        }
        TreeNode* root = new TreeNode(0);
        root->val = nums[maxi];
        len--;
        root->left = _constructMaximumBinaryTree(nums, begin, maxi - 1, len);
        root->right = _constructMaximumBinaryTree(nums, maxi + 1, end, len);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return new TreeNode(nums[0]);
        }
        int len = nums.size() - 1;
        return _constructMaximumBinaryTree(nums, 0, nums.size() - 1, len);

    }
};