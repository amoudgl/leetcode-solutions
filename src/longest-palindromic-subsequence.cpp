// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int i, j, n = s.length();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for (i = n-1; i >= 0; i--)
        {
            for (j = i; j < n; j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j])
                {
                    if (j == i+1)
                        dp[i][j] = 2;
                    else 
                        dp[i][j] = dp[i+1][j-1] + 2;
                }
                else if (s[i] != s[j])
                {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
