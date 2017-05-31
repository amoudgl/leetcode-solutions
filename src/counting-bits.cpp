// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        int i, pow=2;
        dp[0] = 0;
        if (num >= 1)
            dp[1] = 1;
        if (num >= 2)
            dp[2] = 1;
        for (i = 3; i <= num; i++)
        {
            if (i == 2*pow)
            {
                pow = pow*2;
                dp[i] = 1;
            }
            else 
                dp[i] = dp[i-pow] + 1;
        }
        return dp;
    }
};
