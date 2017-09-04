// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.length(), N = word2.length();
        vector<vector<int> > dp(M+1, vector<int> (N+1, 0));
        dp[0][0] = 0;
        for (int i = 1; i <= M; i++) dp[i][0] = i;
        for (int i = 1; i <= N; i++) dp[0][i] = i;
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int x1 = dp[i-1][j];
                int x2 = dp[i-1][j-1];
                int x3 = dp[i][j-1];
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1 + min(x1, min(x2, x3));
                }
            }
        }
        return dp[M][N];
    }
};
