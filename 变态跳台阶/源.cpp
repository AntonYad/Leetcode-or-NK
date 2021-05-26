class Solution {
public:
    int jumpFloorII(int number)
    {
        if (number == 0)
        {
            return 0;
        }
        if (number == 1)
        {
            return 1;
        }
        int i;
        int ret = 1;
        for (i = 2; i <= number; i++)
        {
            ret = ret * 2;
        }
        return ret;
    }
};