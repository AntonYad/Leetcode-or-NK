class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] > nums[i - 1])
            {
                count++;
                max = count > max ? count : max;
            }
            else
            {
                max = count > max ? count : max;
                count = 1;
            }
        }
        return max;

    }
};