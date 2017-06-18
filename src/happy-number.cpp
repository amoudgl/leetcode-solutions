// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        unordered_set<long long int> s;
        long long int N = n;
        while (N != 1)
        {
            N = GetSquareSum(N);
            if (s.find(N) == s.end()) s.insert(N);
            else return false;
        }
        return true;
    }
    long long int GetSquareSum(long long int n)
    {
        string num = to_string(n);
        long long int sum = 0;
        for (int i = 0; i < num.length(); i++)
        {
            sum += ((num[i]-48)*(num[i]-48));
        }
        return sum;
    }
};
