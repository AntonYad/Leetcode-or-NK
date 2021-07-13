class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0)
        {
            return 0;
        }
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int index = s.size() - 1;
        int count = 0;
        for (int i = g.size() - 1; i >= 0; i--)
        {
            if (index >= 0 && s[index] >= g[i])
            {
                count++;
                index--;
            }
        }
        return count;
    }
};