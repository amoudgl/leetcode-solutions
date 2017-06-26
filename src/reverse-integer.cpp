// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int reverse(int x) {
        string num = to_string(x);
        int i = 0, ans = 0;
        if (x < 0) i = 1;
        int ten = 1, overflow = 0;
        for (; i < num.length(); i++)
        {
            if (overflow) return 0;
            int digit = num[i]-48;
            if (digit > INT_MAX/ten || ans > INT_MAX - (digit*ten)) return 0;
            else ans = ans + (digit*ten);
            
            if (ten > INT_MAX/10) overflow = 1;
            else ten = ten * 10;
        }
        if (x < 0) return -ans;
        return ans;
    }
};
