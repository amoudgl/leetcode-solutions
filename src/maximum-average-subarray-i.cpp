// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < k; i++) sum += nums[i];
        double av = (double)sum / (double)k;
        double ans = av;
        for (int i = k; i < n; i++)
        {
            sum += nums[i];
            sum -= nums[i-k];
            av = (double)sum / (double)k;
            if (av > ans) ans = av;
        }
        return ans;
    }
};
