static string arr[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
class Solution {
public:
    void dfs(string digits, vector<string>& res, int index, string str)
    {
        if (index == digits.size())
        {
            if (!str.empty())
            {
                res.push_back(str);
            }
            return;
        }
        string curarr = arr[digits[index] - '0'];
        for (auto e : curarr)
        {
            dfs(digits, res, index + 1, str + e);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        dfs(digits, res, 0, "");
        return res;
    }
};