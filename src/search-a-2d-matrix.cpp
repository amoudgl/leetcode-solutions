// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int i = lowerbound(matrix, target, 0, m-1);
        cout << i << endl;
        return bsearch(matrix, target, i, 0, n-1) >= 0 ? true : false;
    }
    int lowerbound(vector<vector<int>> &matrix, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (matrix[mid][0] == target)
                return mid;
            else if (target > matrix[mid][0])
                return lowerbound(matrix, target, mid+1, n);
            else if (target < matrix[mid][0])
                return lowerbound(matrix, target, m, mid-1);
        }
        return max(n, 0); 
    }
    int bsearch(vector<vector<int>> &matrix, int target, int i, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (matrix[i][mid] == target)
                return mid;
            else if (target > matrix[i][mid])
                return bsearch(matrix, target, i, mid+1, n);
            else if (target < matrix[i][mid])
                return bsearch(matrix, target, i, m, mid-1);
        }
        return -1;
    }
};
