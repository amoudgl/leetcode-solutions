// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fR = -1, fC = -1;
        int m = matrix.size(), n = matrix[0].size();
        
        // find first column with zero element
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i] == 0)
                {
                    fC = i;
                    break;
                }
            }
            if (fC >= 0) break;
        }
        
        // find first row with zero element 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    fR = i;
                    break;
                }
            }
            if (fR >= 0) break;
        }
        // if no zero element, return
        if (fR < 0) return;
        
        // if any element in a row is zero
        // save it in fC column
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][fC] = 0;
                    break;
                }
            }
        }
        
        // if any element in a column is zero
        // save it in fR row       
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i] == 0)
                {
                    matrix[fR][i] = 0;
                    break;
                }
            }
        }
        
        // zero out rows saved in fC column
        for (int i = 0; i < m; i++)
        {
            if (i != fR && matrix[i][fC] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // zero out columns saved in fR row
        for (int i = 0; i < n; i++)
        {
            if (i != fC && matrix[fR][i] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        // zero out fC row and fC column
        for (int i = 0; i < n; i++)
        {
            matrix[fR][i] = 0;
        }
        for (int j = 0; j < m; j++)
        {
            matrix[j][fC] = 0;
        }
    }
};
