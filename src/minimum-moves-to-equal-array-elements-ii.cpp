// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), mid, ans = 0;
        mid = nums[n/2];
        for (int n : nums) ans += abs(mid-n);
        return ans;
    }
};
