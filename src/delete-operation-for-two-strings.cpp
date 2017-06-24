// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l = findLCA(word1, word2);
        return word1.length()-l + word2.length()-l;
    }
    int findLCA(string &s1, string &s2)
    {
        int m = s1.length();
        int n = s2.length();
        if (m == 0 || n == 0) return 0;
        vector<vector<int> > dp(m, vector<int> (n, 0));
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (!flag && s1[0] == s2[i])
            {
                flag = 1;
                dp[0][i] = 1;
            }
            else if (flag) dp[0][i] = 1;
        }
        flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (!flag && s1[i] == s2[0])
            {
                flag = 1;
                dp[i][0] = 1;
            }
            else if (flag) dp[i][0] = 1;
        }        
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if (s1[i] != s2[j])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
