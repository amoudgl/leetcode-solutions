// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> strings; 
        int i, j, N = strs.size();
        for (i = 0; i < N; i++)
        {
            strings.push_back(CountOnesAndZeros(strs[i]));
        }
        int dp[102][102];
        for (int i = 0; i < 102; i++)
        {
            for (int j = 0; j < 102; j++)
                dp[i][j] = 0;
        }
        return FindMaxStrings(dp, strings, m, n);
    }
    int FindMaxStrings(int dp[102][102], vector<pair<int, int>> &strings, int m, int n)
    {
        if (m < 0 || n < 0 || (m == 0 && n == 0))
            return 0;
        int i, j, k;
        for (i = 0; i < strings.size(); i++)
        {
            for (j = m; j >= strings[i].first; j--)
            {
                for (k = n; k >= strings[i].second; k--)
                {
                    dp[j][k] = max(dp[j][k], 1+dp[j-strings[i].first][k-strings[i].second]);
                }
            }
        }
        return dp[m][n];
    }
    pair<int, int> CountOnesAndZeros(string s)
    {
        int i;
        auto p = make_pair(0, 0);
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == '0') p.first++;
            else if (s[i] == '1') p.second++;
        }
        return p;
    }
};
