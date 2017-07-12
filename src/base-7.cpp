// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if (num == 0) return "0";
        int flag = (num < 0) ? 1 : 0;
        num = abs(num);
        while (num > 0)
        {
            int x = num % 7;
            num = num/7;
            ans += to_string(x);
        }
        if (flag) ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
