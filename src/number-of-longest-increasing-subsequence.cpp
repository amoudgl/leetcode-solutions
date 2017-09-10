// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), mx = 0, ans = 0;
        vector<int> dp(n, 0);
        vector<int> counts(n, 0);
        for (int i = 0; i < n; i++)
        {
            int m = 0, count = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] > m)
                    {
                        m = dp[j];
                        count = counts[j];
                    }
                    else if (dp[j] == m)
                    {
                        count += counts[j];
                    }
                }
            }
            dp[i] = m + 1;
            counts[i] = count;
            if (dp[i] > mx)
            {
                ans = count;
                mx = dp[i];
            }
            else if (dp[i] == mx) ans += count;
        }
        return ans;
    }
};
