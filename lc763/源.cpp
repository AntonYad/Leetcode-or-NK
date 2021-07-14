class Solution {
public:
    vector<int> partitionLabels(string s) {

        int hash[27] = { 0 };
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        vector<int> v;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);
            if (i == right)
            {
                v.push_back((right - left + 1));
                left = right + 1;
            }
        }
        return v;
    }
};