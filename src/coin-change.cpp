// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        int i, j, mincoins=-1, n = coins.size();
        for (i = 1; i <= amount; i++)
        {
            mincoins = -1;
            for (j = 0; j < n; j++)
            {
                if (mincoins == -1 && i-coins[j] >= 0 && dp[i-coins[j]] >= 0)
                    mincoins = dp[i-coins[j]]+1;
                else if (i-coins[j] >= 0 && dp[i-coins[j]] >= 0)
                    mincoins = min(mincoins, dp[i-coins[j]]+1);
            }
            dp[i] = mincoins;
        }
        return dp[amount];
    }
};
