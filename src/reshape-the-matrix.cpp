// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (r*c != m*n) return nums;
        int i = 0, j = 0, p = 0, q = 0;
        vector<vector<int> > ans(r, vector<int> (c));
        while (i < m)
        {
            ans[p][q] = nums[i][j];
            j++;
            if (j == n)
            {
                i++;
                j = 0;
            }
            q++;
            if (q == c)
            {
                p++;
                q = 0;
            }
        }
        return ans;
    }
};
