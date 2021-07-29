class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        vector<int> res(nums.size() + 1, 0);
        for (auto& e : nums)
        {
            if (e > 0 && e <= nums.size())
                res[e] = e;
        }
        for (int i = 1; i < res.size(); i++)
        {
            if (res[i] != i)
            {
                return i;
            }
        }
        return res.size();
    }
};