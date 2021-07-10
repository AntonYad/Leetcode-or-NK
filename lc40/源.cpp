class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    void _combinationSum2(vector<int>& candidates, int sum, int index, int target)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            vv.push_back(v);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            v.push_back(candidates[i]);
            _combinationSum2(candidates, sum + candidates[i], i + 1, target);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        _combinationSum2(candidates, 0, 0, target);
        return vv;
    }
};