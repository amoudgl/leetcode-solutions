// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
		long long int sum = 0;
        for (long long int i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                sum += i;
                sum += (num/i);
                if (i*i == num || i == 1) sum -= (num/i);
            }
            if (sum > num) break;
        }
        if (sum == num) return true;
        return false;
    }
};
