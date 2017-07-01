// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        int num = 0, x = 1;
        for (int i = 0; i < s.length(); i++)
        {
            num += ((s[i]-'A'+1)*x);
            x *= 26;
        }
        return num;
    }
};
