class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        vector<int> res;
        int end = num.size() - 1;
        int carry = 0;
        for (int i = end; i >= 0; i--)
        {
            int sum = num[i] + k % 10;
            k = k / 10;
            if (sum >= 10)
            {
                k++;
                sum = sum - 10;
            }
            res.push_back(sum);
        }
        while (k != 0)
        {
            int i = k % 10;
            res.push_back(i);
            k = k / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

};