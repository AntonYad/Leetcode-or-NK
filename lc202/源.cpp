class Solution {
public:
    int getsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum = sum + (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> s;

        while (1)
        {
            int sum = getsum(n);
            if (sum == 1)
            {
                return true;
            }
            if (s.find(sum) != s.end())
            {
                return false;
            }
            else
            {
                s.insert(sum);
                n = sum;
            }

        }



    }
};