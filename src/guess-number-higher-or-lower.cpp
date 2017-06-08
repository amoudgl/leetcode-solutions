// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return bsearch(1, n);
    }
    int bsearch(int m, int n)
    {
        if (m <= n)
        {
            int mid = m + (n-m)/2;
            if (guess(mid) == 0) return mid;
            else if (guess(mid) < 0) return bsearch(m, mid-1);
            else if (guess(mid) > 0) return bsearch(mid+1, n);
        }
        return max(min(m, n), 1);
    }
};
