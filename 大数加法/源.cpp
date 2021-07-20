class Solution {
public:
    string solve(string s, string t) {
        if (s.empty()) return t;
        if (t.empty()) return s;
        if (s.size() < t.size()) swap(s, t);
        int tail = s.size() - t.size();
        int carry = 0, temp = 0;
        while (tail--) t = '0' + t;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            temp = carry + s[i] - '0' + t[i] - '0';
            if (temp >= 10)
            {
                carry = 1;
                temp = temp - 10;
            }
            else
            {
                carry = 0;
            }
            s[i] = temp + '0';
        }
        if (carry == 1)
        {
            s = '1' + s;
        }
        return s;
    }
};