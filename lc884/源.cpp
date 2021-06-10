class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> um;
        vector<string> v;
        string s = s1 + " " + s2;
        for (int i = 0; i < s.size(); i++)
        {
            string temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            v.push_back(temp);
        }
        for (auto& e : v)
        {
            um[e]++;
        }
        v.clear();
        for (auto& e : um)
        {
            if (e.second == 1)
            {
                v.push_back(e.first);
            }
        }
        return v;
    }
};