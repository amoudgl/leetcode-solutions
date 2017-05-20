// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while (num > 0)
        {
            int digit = num % 2;
            digit = digit ^ 1;
            ans += digit * pow(2, i);
            i++;
            num = num/2;
        }
        return ans;
    }
};
