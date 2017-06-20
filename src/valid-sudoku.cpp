// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.' && s.find(board[i][j]-48) != s.end())
                {
                    return false;
                }
                else if (board[i][j] != '.')
                    s.insert(board[i][j]-48);
            }
            s.clear();
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] != '.' && s.find(board[j][i]-48) != s.end())
                {
                    return false;
                }
                else if (board[j][i] != '.')
                    s.insert(board[j][i]-48);                
            }
            s.clear();
        }
        for (int k = 0; k < 9; k++)
        {
            int m = k/3 * 3;
            int n = (k % 3) * 3;
            for (int i = m; i < m+3; i++)
            {
                for (int j = n; j < n+3; j++)
                {
                    if (board[i][j] != '.' && s.find(board[i][j]-48) != s.end())
                    {
                        return false;
                    }
                    else if (board[i][j] != '.')
                        s.insert(board[i][j]-48);     
                }
            }
            s.clear();
        }
        return true;
    }
};
