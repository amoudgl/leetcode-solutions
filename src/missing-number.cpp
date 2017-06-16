// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        ans = ans ^ n;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
            ans = ans ^ i;
        }
        return ans;
    }
};
