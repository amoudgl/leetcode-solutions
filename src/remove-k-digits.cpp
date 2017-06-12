// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<pair<int, int>> st;
        int j = 0, n = num.length(), indmax = k, i;
        string ans;
        while (ans.length() < n-k)
        {
            int min = num[j]-48, ind = j;
            for (i = j; i <= indmax; i++)
            {
                if (num[i]-48 < min)
                {
                    min = num[i]-48;
                    ind = i;
                }
            }
            ans += to_string(min);
            j = ind+1;
            indmax++;
        }
        ans = PostProcess(ans);
        return ans;
    }
    string PostProcess(string s)
    {
        string ans;
        int flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '0') flag = 1;
            if (flag) ans += s[i];
        }
        s.clear();
        if (ans.length() == 0) return "0";
        return ans;
    }
};
