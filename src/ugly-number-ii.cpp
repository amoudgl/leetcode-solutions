// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int i1=0, i2=0, i3=0;
        for (int i = 1; i < n; i++)
        {
            int m = min(dp[i1]*2, min(dp[i2]*3, dp[i3]*5));
            dp[i] = m;
            if (m == dp[i1]*2) i1++;
            if (m == dp[i2]*3) i2++;
            if (m == dp[i3]*5) i3++;
        }
        return dp[n-1];
    }
};
