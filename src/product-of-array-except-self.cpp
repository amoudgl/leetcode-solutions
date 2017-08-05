// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int> output(n, 1);
        for (i = n-1; i >= 0; i--)
        {
            if (i+1 < n) output[i] = output[i+1]*nums[i+1];
            else if (i == n-1) output[i] = 1;
        }
        int prod = 1;
        for (i = 0; i < n; i++)
        {
            if (i-1 >= 0)
            {
                prod = prod*nums[i-1];
                output[i] = output[i]*prod;
            }
        }
        return output;
    }
};
