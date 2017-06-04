// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        int i, j; 
        for (i = 3; i <= n; i++)
        {
            
            for (j = 1; j <= i/2; j++)
            {
                dp[i] = max(dp[i], FindMax(dp[i-j]*dp[j],
                                           i-j*dp[j],
                                           dp[i-j]*j,
                                           (i-j)*j));
            }
        }
        return dp[n];
    }
    int FindMax(int a, int b, int c, int d)
    {
        int ans = max(a, b);
        ans = max(ans, c);
        ans = max(ans, d);
        return ans;
    }
};
