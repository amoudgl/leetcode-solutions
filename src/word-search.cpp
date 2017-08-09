// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (word.length() == 0 || word.length() > m*n) return false;
        vector<vector<bool> > visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (f(board, word, i, j, 0, visited)) return true;
                }
            }
        }
        return false;
    }
    bool f(vector<vector<char>>& board, string word, int m, int n, int k, vector<vector<bool> > visited)
    {
        if (k == word.length()) return true;
        if (m >= board.size() || n >= board[0].size()) return false;
        if (visited[m][n]) return false;
        if (board[m][n] == word[k])
        {
                visited[m][n] = true;
                if (!f(board, word, m+1, n, k+1, visited))
                {
                    if (!f(board, word, m-1, n, k+1, visited))
                    {
                        if (!f(board, word, m, n+1, k+1, visited))
                        {
                            if (!f(board, word, m, n-1, k+1, visited))
                                return false;
                        }
                    
                    }
                
                }
                return true;
        }
        else if (board[m][n] != word[k])
            return false;
    }
};
