class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            v1[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            v2[t[i] - 'a']++;
        }
        int j = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[j])
            {
                return false;
            }
            j++;
        }
        return true;
    }
};