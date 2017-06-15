// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n <= 0) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int k = primes.size();
        vector<int> pointers(k, 0);
        priority_queue<pair<int, int> > minheap;
        for (int i = 0; i < k; i++)
        {
            minheap.push(make_pair(-primes[i], i));
        }
        for (int i = 1; i < n; i++)
        {
            int m = abs(minheap.top().first);
            dp[i] = m;
            while (abs(minheap.top().first) == m)
            {
                int ind = minheap.top().second;
                minheap.pop();
                pointers[ind]++;
                minheap.push(make_pair(-dp[pointers[ind]]*primes[ind], ind));
            }
        }
        return dp[n-1];
    }
};
