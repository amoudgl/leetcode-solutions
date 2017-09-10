// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findIntegers(int num) {
        vector<int> dp(32, 0);
        dp[0] = 0;
        dp[1] = 2;
        dp[2] = 3;
        for (int i = 3; i <= 32; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return f(num, dp);
    }
    int f(int n, vector<int> &dp)
    {
        if (n == 0) return 1;
        else if (n <= 2) return dp[n];
        else if (n == 3) return n;
        int msb = 0, i = 0, num = n;
        while (n > 0)
        {
            i++;
            int x = n % 2;
            if (x == 1) msb = i;
            n /= 2;
        }
        int y;
        if ((num&(1<<(msb-2))) == 0)
        {
            int x = (num&((1<<(msb-2)) - 1));
            y = f(x, dp);
        }
        else 
            y = dp[msb-2];
        return dp[msb-1] + y;
    }
};
