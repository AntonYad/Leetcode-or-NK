class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        int m = 1;
        while ((ret & m) == 0)
        {
            m = m << 1;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & m)
            {
                x ^= nums[i];
            }
            else
            {
                y ^= nums[i];
            }
        }
        vector<int> n = { x,y };
        return n;
    }
};