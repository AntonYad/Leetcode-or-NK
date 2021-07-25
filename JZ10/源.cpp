class Solution {
public:
    int rectCover(int number) {
        if (number <= 2)
        {
            return number;
        }
        int dp[3];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; i++)
        {
            int sum = dp[2] + dp[1];
            dp[1] = dp[2];
            dp[2] = sum;
        }
        return dp[2];
    }
};