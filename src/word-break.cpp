// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        if (sl == 0) return true;
        int n = wordDict.size();
        if (n == 0) return false;
        vector<vector<int>> dp(sl, vector<int> (sl, -1));
        unordered_map<string, bool> dict;
        for (int i = 0; i < n; i++)
        {
            dict[wordDict[i]] = true;
        }
        bool ans = fun(s, dp, dict, 0, sl-1);
        return ans;
    }
    bool fun(string s, vector<vector<int>> &dp, unordered_map<string, bool> &dict, int m, int n)
    {
        if (m > n)
            return true;
        else if (dp[m][n] > -1)
            return ToBool(dp[m][n]);
        else if (m == n)
        {
            if  (dict.find(s.substr(m, 1)) == dict.end())
                dp[m][n] = 0;
            else 
                dp[m][n] = 1;
            return ToBool(dp[m][n]);
        }
        for (int i = m; i <= n; i++)
        {
            bool x1, x2, y1, y2;
            x1 = fun(s, dp, dict, m, i);
            x2 = dict.find(s.substr(m, i-m+1)) == dict.end() ? false : true;
            y1 = fun(s, dp, dict, i+1, n);
            y2 = dict.find(s.substr(i+1, n-i)) == dict.end() ? false : true;
            if (((x1 || x2) && (y1 || y2)) == true)
            {
                dp[m][n] = 1;
                break;
            }
            else
                dp[m][n] = 0;
        }
        return ToBool(dp[m][n]);
    }
    bool ToBool(int x)
    {
        if (x == 1) return true;
        return false;
    }
};
