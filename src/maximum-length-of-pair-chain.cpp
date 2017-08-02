// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size(), i;
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int m = 0;
            int c = pairs[i][0];
            for (int j = 0; j < i; j++)
            {
                int b = pairs[j][1];
                if (b < c) m = max(m, dp[j]);
            }
            dp[i] = m + 1;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
