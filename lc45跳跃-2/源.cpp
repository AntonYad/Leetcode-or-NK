class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return 0;
        }
        int count = 0;
        int cur = 0;
        int trend = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            trend = max(i + nums[i], trend);
            if (i == cur)
            {
                if (cur != nums.size() - 1)
                {
                    count++;
                    if (trend >= nums.size() - 1)
                    {
                        break;
                    }
                    cur = trend;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};