// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) 
            return 0;
        vector<int> dp(n, 0);
        int i, j, ans = 0;
        for (i = 0; i < n; i++)
        {
            int max = 0;
            for (j = i-1; j >= 0; j--)
            {
                if (nums[j] < nums[i] && dp[j] > max)
                {
                    max = dp[j];
                }
            }
            dp[i] = max+1;
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};
