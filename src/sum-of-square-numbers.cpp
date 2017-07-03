// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> squares;
        squares.insert(0);
        for (long long int i = 1; i <= sqrt(c); i++)
            if (i*i <= c) squares.insert(i*i);
        for (auto p : squares)
            if (squares.find(c-p) != squares.end()) return true;
        return false;
    }
};
