// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        int i = 1, j; 
        vector<int> a;
        while (1)
        {
            if (i < INT_MAX/i && i*i <= n)
                a.push_back(i*i);
            else if (i > INT_MAX/i || i < INT_MAX/i && i*i > n)
                break;
            i++;
        }
        vector<int> dp(n+1, 0);
        int N = a.size();
        for (i = 1; i <= n; i++)
        {
            int min = INT_MAX;
            for (j = 0; j < N; j++)
            {
                if (i-a[j] >= 0 && 1 + dp[i-a[j]] < min)
                    min = 1 + dp[i-a[j]];
            }
            dp[i] = min;
        }
        return dp[n];
    }
};
