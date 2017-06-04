// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[0].size();
        vector<vector<int> > dp;
        for (int i = 0; i < triangle.size(); i++)
        {
            vector<int> a;
            dp.push_back(a);
            for (int j = 0; j < triangle[i].size(); j++)
                dp[i].push_back(-1);
        }
        int ans = MinPathSum(triangle, dp, 0, 0);
        return ans;
    }
    int MinPathSum(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        else if (i == triangle.size()-1)
            return dp[i][j] = triangle[i][j];
        else
            return dp[i][j] = triangle[i][j] + min(MinPathSum(triangle, dp, i+1, j),
                                                   MinPathSum(triangle, dp, i+1, j+1));
    }
};
