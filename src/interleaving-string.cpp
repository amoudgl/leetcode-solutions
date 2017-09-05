// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int I = s1.length(), J = s2.length(), K = s3.length();
        vector<vector<vector<pair<bool, bool>>>> dp(I+1, vector<vector<pair<bool, bool>>> 
                                                    (J+1, vector<pair<bool, bool>> (K+1, pair<bool, bool> (false,false)))); 
        return f(0, 0, 0, s1, s2, s3, dp);
    }
    bool f(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<pair<bool, bool>>>> &dp)
    {
        if (dp[i][j][k].first == true) return dp[i][j][k].second;
        bool x;
        if (k == s3.length())
        {
            if (i == s1.length() && j == s2.length()) x = true;
            else x = false;
            dp[i][j][k].first = true;
            dp[i][j][k].second = x;
            return x;
        }
        if (j < s2.length() && i < s1.length() && s3[k] == s1[i] && s3[k] == s2[j])
        {
            bool x1 = f(i+1, j, k+1, s1, s2, s3, dp);
            bool x2 = f(i, j+1, k+1, s1, s2, s3, dp);
            if (x1 == true || x2 == true) x = true;
            else x = false;
            dp[i][j][k].first = true;
            dp[i][j][k].second = x;
            return x;
        }
        else if (s3[k] == s1[i] && (j == s2.length() || s3[k] != s2[j]))
        {
            x = f(i+1, j, k+1, s1, s2, s3, dp);
            dp[i][j][k].first = true;
            dp[i][j][k].second = x;
            return x;
        }
        else if (s3[k] == s2[j] && (i == s1.length() || s3[k] != s1[i] ))
        {
            x = f(i, j+1, k+1, s1, s2, s3, dp);
            dp[i][j][k].first = true;
            dp[i][j][k].second = x;;
            return x;            
        }
        else if (s3[k] != s1[i] && s3[k] != s2[j])
        {
            x = false;
            dp[i][j][k].first = true;
            dp[i][j][k].second = x;
            return x;
        }
    }
};
