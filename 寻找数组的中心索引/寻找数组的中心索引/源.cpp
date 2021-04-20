class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int leftsum = 0, rightsum = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			rightsum += nums[i];
		}
		for (int j = 0; j<nums.size(); j++)
		{
			leftsum += nums[j];
			if (leftsum == rightsum)
			{
				return j;
			}
			rightsum -= nums[j];
		}
		return -1;
	}
};