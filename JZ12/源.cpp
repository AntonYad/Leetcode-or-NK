class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1.0;
        if (base == 0.0) return 0.0;
        int flag = 0;
        double res = base;
        if (exponent < 0)
        {
            flag = 1;
            exponent *= -1;
        }
        for (int i = 2; i <= exponent; i++)
        {
            res *= base;
        }
        if (flag)
        {
            res = 1.0 / res;
        }
        return res;
    }
};