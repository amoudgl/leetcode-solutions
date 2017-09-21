// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0; i <= 30; i++)
        {
            int p = 1 << i;
            if (n-m < p)
            {
                int x = (p & m) >> i;
                int y = (p & n) >> i;
                int z = x & y;
                ans += (z * p);
            }
        }
        return ans;
    }
};
