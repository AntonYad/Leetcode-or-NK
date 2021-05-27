class Solution {
public:
    /**
     *	正数数组中的最小不可组成和
     *	输入：正数数组arr
     *	返回：正数数组中的最小不可组成和
     */
    int getFirstUnFormedNum(vector<int> arr, int len) {
        int min = arr[0], max = arr[0];
        for (int i = 1; i < len; i++)
        {
            max = max + arr[i];
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        //出来就有了背包的容量 max
        vector<int> f(max + 1, 0);
        for (int i = 0; i < len; i++)
        {
            for (int j = max; j >= arr[i]; j--)
            {
                if (f[j] < f[j - arr[i]] + arr[i])
                {
                    f[j] = f[j - arr[i]] + arr[i];
                }
            }
        }
        for (int i = min; i <= max; i++)
        {
            if (f[i] != i)
            {
                return i;
            }
        }
        return max + 1;

    }
};