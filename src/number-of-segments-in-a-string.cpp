// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int countSegments(string s) {
        int i = 1;
        int ans = 0; 
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && (i - 1 >= 0 && s[i - 1] != ' '))
            {
                ans += 1;
            }
        }
        if (s.length() > 0 && s[i - 1] != ' ')
            ans += 1;
        return ans;
    }
};
