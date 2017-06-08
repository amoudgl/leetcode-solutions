// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int arrangeCoins(int n) {
        return bsearch(n, 1, 65535);
    }
    int bsearch(int target, int m, int n)
    {
        
        if (m <= n)
        {
            long long int mid = m+(n-m)/2;
            long long int sum = (mid*(mid+1))/2;
            if (target == sum)
                return mid;
            else if (target > sum)
                return bsearch(target, mid+1, n);
            else if (target < sum)
                return bsearch(target, m, mid-1);
        }
        else 
            return n;
    }
};
