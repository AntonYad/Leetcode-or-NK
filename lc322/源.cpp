class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j - coins[i] >= 0 && dp[j - coins[i]] != INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
        {
            return -1;
        }
        return dp[amount];

    }
};