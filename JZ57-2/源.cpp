class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vv;
        int l = 1;
        int r = l;
        while (r < target)
        {
            int sum = l;
            vector<int> v;
            while (r < target && sum < target)
            {
                v.push_back(r);
                r++;
                sum += r;
            }
            v.push_back(r);
            if (sum == target)
            {
                vv.push_back(v);
            }
            else
            {
                l = l + 1;
                r = l;
            }
        }
        return vv;

    }
};