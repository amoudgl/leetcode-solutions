// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, sz = nums.size();
        for (auto n : nums)
            sum += n;
        if (sum % 2 == 1) return false;
        else sum = sum/2;
        vector<vector<bool> > a(sum+1, vector<bool> (sz, false));
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 1; i <= sum; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (i-nums[j] >= 0 && dp[i-nums[j]] == true && a[i-nums[j]][j] == false)
                {
                    dp[i] = true;
                    a[i] = a[i-nums[j]];
                    a[i][j] = true;
                    break;
                }
            }
        }
        if (dp[sum]) return true;
        return false;
    }
};
