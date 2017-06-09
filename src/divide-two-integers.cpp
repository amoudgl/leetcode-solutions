// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag = (((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : 0);
        if (divisor == 0) return INT_MAX;
        else if (dividend == INT_MIN)
        {
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) return INT_MIN;
            else if (divisor == INT_MIN) return 1;
            divisor = abs(divisor);
            int ans = 1, k = divisor;
            while (1)
            {
                if (dividend + k*2 > 0 || k > INT_MAX/2)
                    break;
                else
                {
                    k = k*2;
                    ans = ans*2;
                }
            }
            ans += divide(abs(dividend+k), divisor);
            if (!flag) ans = -ans;
            return ans;
        }
        else if (abs(divisor) == 1) return flag == 1 ? abs(dividend): -1*abs(dividend);
        else if (divisor == INT_MIN || abs(divisor) > abs(dividend)) return 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int ans = 1, k = divisor;
        while (1)
        {
            if (dividend - k*2 < 0)
            {
                break;
            }
            else 
            {
                k = k*2; 
                ans = ans*2;
            }
        }
        ans += divide(dividend-k, divisor);
        if (!flag) ans = -ans;
        return ans;
    }
};
