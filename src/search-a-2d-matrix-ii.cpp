// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0 ) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        for (int i = 0; i < m; i++)
        {
            if (target < matrix[i][0])
                return false;
            bool flag = bsearch(matrix, i, 0, n-1, target);
            if (flag)
                return flag;
        }
        return false;
    }
    bool bsearch(vector<vector<int>> &matrix, int i, int m, int n, int target)
    {
        if (m <= n)
        {
            int mid = m + (n-m)/2;
            if (matrix[i][mid] == target)
                return true;
            else if (matrix[i][mid] < target)
                return bsearch(matrix, i, mid+1, n, target);
            else if (matrix[i][mid] > target)
                return bsearch(matrix, i, m, mid-1, target);
        }
        return false;
    }
};
