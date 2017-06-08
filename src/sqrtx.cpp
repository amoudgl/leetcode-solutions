// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int mySqrt(int x) {
    if (x == 0)
        return 0;
    int m = 1, n = x;
    while (true) 
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (x/mid == mid) return mid;
            else if (mid > x/mid) n = mid-1;
            else if (mid < x/mid) m = mid+1;
        }
        else
            return n;
    }
    }
};
