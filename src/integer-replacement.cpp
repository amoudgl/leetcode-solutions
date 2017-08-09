// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int integerReplacement(int n) {
        if (m.find(n) != m.end()) return m[n];
        if (n == 1) return m[n] = 0;
        // else if (n == 0) return m[0] = INT_MAX;
        else if (n % 2 == 0) return m[n] = 1 + integerReplacement(n/2);
        else 
        {
            if (n > INT_MAX-1) return m[n] = min(1 + integerReplacement(n-1), 2 + integerReplacement(n+(1-n)/2));
            else return m[n] = 1 + min(integerReplacement(n+1), integerReplacement(n-1));
        }
    }
private:
    unordered_map<int, int> m;
};
