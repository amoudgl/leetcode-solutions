// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n > 0)
        {
            int i = 1;
            double ans = x;
            while (1)
            {
                if (2*i > n || i >= INT_MAX/2)
                    break;      
                i = i*2;
                ans = ans*ans;
            }
            ans = ans*myPow(x, n-i);
            return ans;
        }
        int i = 1;
        double ans = x;
        n = abs(n);
        while (1)
        {
            if (2*i > n || i >= INT_MAX/2)
                break;             
            i = i*2;
            ans = ans*ans;
        }
        ans = ans*myPow(x, n-i);
        return 1/ans;        
    }
};
