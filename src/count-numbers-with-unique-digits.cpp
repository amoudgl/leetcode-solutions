// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11, 0);
        dp[0] = 1;
        for (int i = 1; i <= 10; i++)
        {
            dp[i] = dp[i-1];
            int x = 9;
            for (int j = 1; j < i; j++)
            {
                x *= (10 - j);
            }
            dp[i] += x;
        }
        if (n > 10)
            return dp[10];
        return dp[n];
    }
};
