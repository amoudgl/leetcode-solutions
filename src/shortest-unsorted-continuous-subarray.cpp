// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> prev;
        prev = nums;
        sort(nums.begin(), nums.end());
        int s = -1, e = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s == -1 && nums[i] != prev[i])
                s = i;
            else if (s > -1 && nums[i] != prev[i])
                e = i;
        }
        if (s == -1) return 0;
        else return e-s+1;
    }
};
