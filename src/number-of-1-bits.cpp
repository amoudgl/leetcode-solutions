// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i <= 31; i++) ans += ((n >> i) & 1);
        return ans;
    }
};
