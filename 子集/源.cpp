class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    void _subsets(vector<int>& nums, int index)
    {
        vv.push_back(v);
        if (index == nums.size())
        {
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            _subsets(nums, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        _subsets(nums, 0);
        return vv;
    }
};