class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return nums.size();
	}
};
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slow = 0;
		for (int fast = 0; fast<nums.size(); fast++)
		{
			if (nums[fast] != val)
			{
				nums[slow++] = nums[fast];
			}
		}
		return slow;
	}
};