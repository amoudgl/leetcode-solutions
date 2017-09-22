// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string shortestPalindrome(string s) {
        int l = s.length();
        string ans = s;
        if (check(s)) return s;
        for (int i = l-1; i >= 0; i--)
        {
            string x = s.substr(0, i+1);
            if (check(x))
            {
                int j = i+1;
                int l1 = l-j;
                string y = s.substr(j, l1);
                reverse(y.begin(), y.end());
                ans = y + s;
                break;
            }
        }
        return ans;
    }
    bool check(string s)
    {
        int i = 0, j = s.length()-1; 
        while (i < j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
