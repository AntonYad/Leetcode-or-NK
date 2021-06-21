class Solution {
public:
    int strToInt(string str) {
        if (str.empty())
            return 0;
        if (str[0] >= 'a' && str[0] <= 'z') return 0;
        int i = 0;
        int max = INT_MAX, min = INT_MIN;
        long res = 0;
        // �ո�
        while (str[i] == ' ')
            i++;
        int sign = 1;
        // ����
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        // ����
        else if (str[i] == '+')
            i++;
        // ��ʽѭ��
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