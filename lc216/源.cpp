class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    void _combinationSum3(int k, int n, int sum, int index)
    {
        if (v.size() == k && sum != 0)
        {
            return;
        }
        if (sum == 0 && k == v.size())
        {
            vv.push_back(v);
            return;
        }
        for (int i = index; i <= 9; i++)
        {
            v.push_back(i);
            _combinationSum3(k, n, sum - i, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = n;
        _combinationSum3(k, n, sum, 1);
        return vv;
    }
};