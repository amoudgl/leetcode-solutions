// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0)
        {
            int digit = n % 26;
            if (digit == 0) ans += "Z";
            else ans += (64 + digit);
			n /= 26;
            if (digit == 0) n -= 1;
        }
		reverse(ans.begin(), ans.end());
        return ans;
    }
};
