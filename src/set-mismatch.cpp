// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(2,0);
        int i, n = nums.size();
        for (i = 0; i < n; i++)
        {
            if (nums[i] == nums[i-1])
                ans[0] = nums[i];
            if (i == 0 && nums[i] != 1)
                ans[1] = 1;
            else if (i > 0 && nums[i] > nums[i-1]+1)
                ans[1] = nums[i]-1;
        }
        if (ans[1] == 0)
            ans[1] = nums[n-1]+1;
        return ans;
    }
};
