class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> vv;
        int left = 1;
        int right = 2;
        while (left < right)
        {
            int max = (left + right) * (right - left + 1) / 2;
            if (max == sum)
            {
                vector<int> v;
                for (int i = left; i <= right; i++)
                {
                    v.push_back(i);
                }
                vv.push_back(v);
                left++;
            }
            else if (max < sum)
            {
                right++;
            }
            else
            {
                left++;
            }
        }
        return vv;
    }
};