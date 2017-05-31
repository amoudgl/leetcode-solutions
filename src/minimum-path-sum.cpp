// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 && n == 0) return 0;
        int dp[m][n];
        int i, j;
        dp[0][0] = grid[0][0];
        int sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        sum = 0;
        for (i = 0; i < m; i++)
        {
            sum += grid[i][0];
            dp[i][0] = sum;
        }
        for (i = 1; i < m; i++)
        {
           for (j = 1; j < n; j++) 
           {
               dp[i][j] = grid[i][j] + FindMin(dp[i-1][j-1]+grid[i][j-1], 
                                               dp[i-1][j-1]+grid[i-1][j], 
                                               dp[i-1][j], 
                                               dp[i][j-1]);
           }
        }
        return dp[m-1][n-1];
    }
    int FindMin(int w, int x, int y, int z)
    {
        int ans = min(w, x);
        ans = min(ans, y);
        ans = min(ans, z);
        return ans;
    }
};
