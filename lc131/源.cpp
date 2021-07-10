class Solution {
public:
    vector<vector<string>> vv;
    vector<string> v;
    void _partition(string& s, int index)
    {
        if (index == s.size())
        {
            vv.push_back(v);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (IsBack(s, index, i))
            {
                string str = s.substr(index, i - index + 1);
                v.push_back(str);
            }
            else
            {
                continue;
            }
            _partition(s, i + 1);
            v.pop_back();
        }
    }
    bool IsBack(const string& s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        _partition(s, 0);
        return vv;


    }
};