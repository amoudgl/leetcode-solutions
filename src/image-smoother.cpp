// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int> > ans(n, vector<int> (m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = 1, sum = M[i][j];
                if (i-1 >= 0 && j-1 >= 0) {count += 1; sum += M[i-1][j-1];}
                if (i-1 >= 0 && j >= 0) {count += 1; sum += M[i-1][j];}  
                if (i-1 >= 0 && j+1 < m) {count += 1; sum += M[i-1][j+1];}
                if (j-1 >= 0) {count += 1; sum += M[i][j-1];}
                if (j+1 < m) {count += 1; sum += M[i][j+1];}
                if (i+1 < n && j-1 >= 0) {count += 1; sum += M[i+1][j-1];}
                if (i+1 < n) {count += 1; sum += M[i+1][j];}
                if (i+1 < n && j+1 < m) {count += 1; sum += M[i+1][j+1];}
                ans[i][j] = sum/count;
            }
        }
        return ans;
    }
};
