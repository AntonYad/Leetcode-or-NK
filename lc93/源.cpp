class Solution {
public:
    vector<string> v;
    void _restoreIpAddresses(string& s, int index, int& point)
    {
        if (point == 3)
        {
            if (Is(s, index, s.size() - 1))
            {
                v.push_back(s);
            }
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (Is(s, index, i))
            {
                s.insert(s.begin() + i + 1, '.');
                point++;
                _restoreIpAddresses(s, i + 2, point);
                point--;
                s.erase(s.begin() + i + 1);
            }
            else
            {
                break;
            }
        }
    }
    bool Is(string s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }
        if (s[start] == '0' && start != end)
        {
            return false;
        }
        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            if (s[i] > '9' || s[i] < '0')
            {
                return false;
            }
            sum = sum * 10 + s[i] - '0';
            if (sum > 255)
            {
                return false;
            }
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int point = 0;
        _restoreIpAddresses(s, 0, point);
        return v;

    }
};