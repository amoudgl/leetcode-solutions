// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int rob(vector<int>& nums) {
        int i, n = nums.size(), ans; 
        if (n == 0)
            return 0;
        vector<pair<int, int> > dp(n);
        dp[0] = make_pair(nums[0], 0);
        ans = nums[0];
        for (i = 1; i < nums.size(); i++)
        {
            pair<int, int> p;
            // includes current element
            p.first = dp[i-1].second + nums[i]; 
            // excludes current element
            p.second = max(dp[i-1].first, dp[i-1].second); 
            if (max(p.first, p.second) > ans)
                ans = max(p.first, p.second);
            dp[i] = p;
        }
        return ans;
    }
};
