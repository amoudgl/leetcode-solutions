// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length(), i;
        if (n == 0)
            return 0;
        else if (n == 1)
        {
            if (s[0] == '0')
                return 0;
            return 1;
        }
        else if (n == 2)
        {
            if (s[0] == '0')
                return 0;
            else if (s[1] == '0')
                return Check(s.substr(0,2));
            else
                return 1 + Check(s.substr(0,2));            
        }
        vector<int> dp(n, 0);
        if (s[0] == '0')
            dp[0] = 0;
        else 
            dp[0] = 1;
        if (s[0] == '0')
            dp[1] = 0;
        else if (s[1] == '0')
            dp[1] = Check(s.substr(0,2));
        else
            dp[1] = 1 + Check(s.substr(0,2));
        for (i = 2; i < n; i++)
        {
            if (s[i] == '0')
                dp[i] =  dp[i-2] * Check(s.substr(i-1,2));
            else
                dp[i] = dp[i-1] + dp[i-2] * Check(s.substr(i-1,2));
        }
        return dp[n-1];
    }
    int Check(string s)
    {
        if (s.length() > 2 || s[0] > '2' ||  s[0] < '1' || (s[0] != '1' && s[1] > '6'))
            return 0;
        return 1;
    }
};
