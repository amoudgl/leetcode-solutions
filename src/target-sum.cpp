// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(); 
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (S > sum)
            return 0;        
        int dp[21][2002];
        memset(dp, -1, sizeof(dp[0][0])*21*2002);  
        int ans = FindWays(nums, n-1, 1000+S, dp);
        return ans;
    }
    int FindWays(vector<int>& nums, int n, int s, int dp[21][2002])
    {
        if (s > 2000 || s < 0) return 0;
        if (dp[n][s] != -1)
            return dp[n][s];
        else if (n == 0)
        {
            int temp = 0;
            if ((s-1000) == nums[n])
                temp += 1;
            if ((s-1000) == -nums[n])
                temp += 1;                
            return temp;
        }
        return dp[n][s] = FindWays(nums, n-1, s-nums[n], dp) + FindWays(nums, n-1, s+nums[n], dp);
    }
};
