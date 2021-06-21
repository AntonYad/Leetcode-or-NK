class Solution {
public:
    int strToInt(string str) {
        if (str.empty())
            return 0;
        if (str[0] >= 'a' && str[0] <= 'z') return 0;
        int i = 0;
        int max = INT_MAX, min = INT_MIN;
        long res = 0;
        // 空格
        while (str[i] == ' ')
            i++;
        int sign = 1;
        // 负号
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        // 正号
        else if (str[i] == '+')
            i++;
        // 正式循环
        while (i < str.size()) {
            if (str[i] >= '0' && str[i] <= '9')
            {
                res = res * 10 + sign * (str[i] - '0');
                if (res > max)
                    return max;
                else if (res < min)
                    return min;
            }
            else
            {
                return res;
            }
            i++;
        }
        return res;
    }
};