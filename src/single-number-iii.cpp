// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int axorb = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            axorb ^= nums[i];
        }
        int lastsetbit = ((axorb & (-axorb)));
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lastsetbit & nums[i]) a ^= nums[i];
            else b ^= nums[i];
        }
        return vector<int> {a, b};
    }
};
