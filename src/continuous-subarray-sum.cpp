// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        k = abs(k);
        int n = nums.size(), r, i;        
        if (k == 0)
        {
            for (i = 1; i < n; i++)
            {
                if (nums[i] == 0 &&  nums[i-1] == 0)
                    return true;
            }
            return false;
        }
        vector<int> dp(n, 0);
        unordered_map<int, int> m;
        dp[0] = nums[0];
        r = dp[0] % k;
        m[r] = 0;
        for (i = 1; i < n; i++)
        {
            dp[i] += (nums[i] + dp[i-1]);
            r = dp[i] % k;
            if (r == 0 || m.find(r) != m.end())
                return true;
            m[r] = i;
        }
        return false;
    }
};
