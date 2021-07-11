class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;

    void _permute(vector<int>& nums, vector<int>& used)
    {
        if (v.size() == nums.size())
        {
            vv.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == 1) continue; // path里已经收录的元素，直接跳过
            used[i] = 1;
            v.push_back(nums[i]);
            _permute(nums, used);
            v.pop_back();
            used[i] = 0;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        _permute(nums, used);
        return vv;

    }
};