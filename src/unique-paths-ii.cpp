// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (m <= 0 || n <= 0 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else
                {
                    if (i-1 >= 0 && obstacleGrid[i-1][j] == 0)
                        dp[i][j] += dp[i-1][j];
                    if (j-1 >= 0 && obstacleGrid[i][j-1] == 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
