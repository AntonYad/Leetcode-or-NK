class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> um;
        for (auto& e : str)
        {
            um[e]++;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (um[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};