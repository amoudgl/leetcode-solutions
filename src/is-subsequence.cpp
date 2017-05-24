// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, prev = -1, m = s.length(), n = t.length();
        for (i = 0; i < m; i++)
        {
            int temp = FindChar(t, prev, s[i], n);
            if (temp > prev)
                prev = temp;
            else
                return false;
        }
        return true;
    }
    int FindChar(string t, int prev, char c, int n)
    {
        int ans;
        for (int j = prev+1; j < n; j++)
        {
            if (t[j] == c)
                return j;
        }
        return -1;
    }
};
