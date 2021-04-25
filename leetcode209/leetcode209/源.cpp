class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int sum = 0;
		int i = 0;
		int length = 0;
		int endlength = INT_MAX;
		for (int j = 0; j<nums.size(); j++)
		{
			sum = sum + nums[j];
			while (sum >= target)
			{
				length = j - i + 1;
				endlength = length<endlength ? length : endlength;
				sum = sum - nums[i++];
			}
		}
		return endlength == INT_MAX ? 0 : endlength;
	}
};