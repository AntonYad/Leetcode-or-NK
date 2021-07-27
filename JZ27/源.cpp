class Solution {
public:
    void dfs(vector<string>& s, vector<int>& used, string& str, string st)
    {
        if (st.size() == str.size())
        {
            s.push_back(st);
            return;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (i > 0 && str[i] == str[i - 1] && used[i - 1] == 0 || used[i] == 1)
            {
                continue;
            }
            used[i] = 1;
            dfs(s, used, str, st + str[i]);
            used[i] = 0;
        }
    }
    vector<string> Permutation(string str) {
        vector<string> s;
        if (str.empty())
        {
            return s;
        }
        vector<int> used(str.size(), 0);
        string st = "";
        dfs(s, used, str, st);
        return s;
    }
};