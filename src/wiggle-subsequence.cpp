// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0; 
        if (n == 0) return 0;
        vector<pair<int, bool>> dp(n, pair<int, bool> (0, false));
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            bool flag = false;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && (dp[j].second == false || dp[j].first == 1) && temp < dp[j].first)
                {
                    temp = dp[j].first;
                    flag = true;
                }
                else if (nums[i] < nums[j] && (dp[j].second == true || dp[j].first == 1) && temp < dp[j].first)
                {
                    temp = dp[j].first;
                    flag = false;
                }
            }
            dp[i].first = temp+1;
            dp[i].second = flag;
            ans = max(ans, dp[i].first); 
        }
        return ans;
    }
};
