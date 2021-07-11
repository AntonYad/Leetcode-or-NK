class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    void _permuteUnique(vector<int>& nums, vector<int>& used)
    {
        if (v.size() == nums.size())
        {
            vv.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1 || ((i > 0) && ((nums[i] == nums[i - 1]) && (used[i - 1] == 0))))
            {
                continue;
            }

            used[i] = 1;
            v.push_back(nums[i]);
            _permuteUnique(nums, used);
            v.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> used(nums.size(), 0);
        _permuteUnique(nums, used);
        return vv;

    }
};