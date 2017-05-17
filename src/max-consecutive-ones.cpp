// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, max = 0, count = 0, n = nums.size();
        if (n == 0) return 0;
        else if (nums[0] == 1) count++;
        for (i = 1; i < n; i++)
        {
            if (nums[i] == 1 && nums[i-1] == 1)
                count++;
            else if (nums[i] == 0 && nums[i-1] == 1 && count > max)
            {
                max = count;
                count = 0;
            }
            else if (nums[i] == 1 && nums[i-1] == 0)
                count = 1;
            else if (nums[i] == 0 && nums[i-1] == 0)
                count = 0;
            if (count > max)
                max = count;
        }
        if (count > max)
            max = count;
        return max;
    }
};
