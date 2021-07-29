class Solution {
public:
    int StrToInt(string str) {
        if (str.size() == 0)
        {
            return 0;
        }
        for (auto& e : str)
        {
            if (e >= '0' && e <= '9' || e == '+' || e == '-')
            {
                continue;
            }
            return 0;
        }
        int flag = 1;
        int i = 0;
        if (str[i] == '-')
        {
            i++;
            flag = -1;
        }
        else if (str[i] == '+')
        {
            i++;
        }
        int sum = 0;
        for (; i < str.size(); i++)
        {
            sum = sum * 10 + (str[i] - '0');
        }

        return sum * flag;
    }
};