class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
		}
		int i;
		for (i = 0; i<nums.size(); i++)
		{
			if (target <= nums[i])
			{
				return i;
			}
		}
		if (target>nums[nums.size() - 1])
		{
			return nums.size();
		}

		return 0;
	}
};