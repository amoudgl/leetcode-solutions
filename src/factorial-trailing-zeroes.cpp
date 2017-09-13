// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int trailingZeroes(int n) {
        int x1 = f(n, 2);
        int x2 = f(n, 5);
        return min(x1, x2);
    }
    int f(int n, int k)
    {
        if (n == 0) return 0;
        else return n/k + f(n/k, k);
    }
        
};
