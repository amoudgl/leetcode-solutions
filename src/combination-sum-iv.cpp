// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        int n = nums.size(), i, j;
        dp[0] = 1;
        for (i = 1; i <= target; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i-nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
