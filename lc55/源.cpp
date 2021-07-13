class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return true;
        }
        int trend = 0;
        for (int i = 0; i <= trend; i++)
        {
            trend = max(i + nums[i], trend);
            if (trend >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};