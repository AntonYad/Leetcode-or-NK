class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                res[j] = nums[i];
                j++;
            }
            else
            {
                res[len - 1] = nums[i];
                len--;
            }
        }
        return res;
    }
};