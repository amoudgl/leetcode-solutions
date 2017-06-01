// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int i, j, k, max = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (i = 0; i < n; i++)
        {
            if (matrix[0][i] == '0')
                dp[0][i] = 0;
            else 
            {
                dp[0][i] = 1;
                max = 1;
            }
        }
        for (i = 0; i < m; i++)
        {
            if (matrix[i][0] == '0')
                dp[i][0] = 0;
            else
            {
                max = 1;
                dp[i][0] = 1;
            }
        }
        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                int flag = 0;
                if (matrix[i][j] == '1')
                {
                    int x = dp[i-1][j-1];
                    for (k = 1; k <= x; k++)
                    {
                        if (matrix[i][j-k] != '1' || matrix[i-k][j] != '1')
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = k;
                }
                if (dp[i][j] > max)
                    max = dp[i][j];                
            }
        }
        return max*max;
    }
};
