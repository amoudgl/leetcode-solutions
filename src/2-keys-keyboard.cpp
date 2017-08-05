// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            int m = INT_MAX;
            for (int j = 1; j < i; j++)
            {
                if (i % j == 0)
                    m = min(m, dp[j]+i/j);
            }
            dp[i] = m;
        }
        return dp[n];
    }
};
