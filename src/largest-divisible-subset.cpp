// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i, j, n = nums.size(), prev, max = 0, ind, maxind, ans = 0;  
        vector<int> largestSet;
        if (n == 0) return largestSet;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n, pair<int, int> (0, -1));
        for (i = 0; i < n; i++)
        {
            int temp = 0;
            ind = -1;
            for (j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[j].first > temp)
                {
                    temp = dp[j].first;
                    ind = j;
                }
            }
            dp[i].first = temp + 1;
            dp[i].second = ind;
            if (dp[i].first > ans)
            {
                ans = dp[i].first;
                maxind = i;
            }
        }
        i = maxind;
        while (i != -1)
        {
            largestSet.push_back(nums[i]);
            i = dp[i].second;
        }
        reverse(largestSet.begin(), largestSet.end());
        return largestSet;
    }
};
