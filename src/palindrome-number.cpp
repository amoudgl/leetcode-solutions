// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isPalindrome(int x) {
        string s1, s2;
        if (x < 0)
            return false;
        while (x > 0)
        {
            int digit = x % 10;
            x = x/10;
            s1 += to_string(digit);
            s2 = to_string(digit) + s2;
        }
        if (s1 == s2)
            return true;
        return false;
    }
};
