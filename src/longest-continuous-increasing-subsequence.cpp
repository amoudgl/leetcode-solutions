// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0) l = 1;
            else if (nums[i] > nums[i-1])
                l++;
            else l = 1;
            ans = max(l, ans);
        }
        return ans;
    }
};
