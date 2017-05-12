// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, ans = 0, n = grid.size(), m = grid[0].size();
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    if ((j-1 >= 0 && grid[i][j-1] == 0) || j-1 < 0)
                        ans += 1;
                    if ((j+1 < m && grid[i][j+1] == 0) || j+1 == m)
                        ans += 1;
                    if ((i-1 >= 0 && grid[i-1][j] == 0) || i-1 < 0)
                        ans += 1;
                    if ((i+1 < n && grid[i+1][j] == 0) || i+1 == n)
                        ans += 1;           
                }
            }
        }
        return ans;
    }
};
