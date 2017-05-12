class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i, sum = 0, ans = INT_MIN;
        for (i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (sum > ans)
                ans = sum;            
            if (sum < 0)
                sum = 0;
        }
        return ans;
    }
};
