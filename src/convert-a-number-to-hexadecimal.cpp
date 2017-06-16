// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unordered_map<int, char> m;
        for (int i = 0; i < 16; i++)
        {
            if (i <= 9) m[i] = i + 48;
            else m[i] = i - 10 + 97;
        }
        string ans;
        unsigned int n;
        if (num < 0)
        {
            n = -num;
            n = ~n;
            n += 1;
        }
        else 
            n = num;
        while (n > 0)
        {
            int x = n % 16;
            ans = m[x] + ans;
            n /= 16;
        }
        return ans;
    }
};
