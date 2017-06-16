// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0)
        {
            int x = a ^ b;
            int carry = a & b;
            a = x;
            b = carry << 1;
        }
        return a;
    }
};
