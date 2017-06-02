// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), x = 0, ans = INT_MIN, temp, temp1, temp2, i;
        if (n == 0)
            return 0;
        for (i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                temp1 = FindMaxProduct(nums, x, i-1);
                temp2 = nums[i];
                x = i+1;
                if (max(temp1, temp2) > ans)
                    ans = max(temp1, temp2);
            }
        }
        temp = FindMaxProduct(nums, x, i-1);  
        if (temp > ans)
            ans = temp;        
        return ans;
    }
    int FindMaxProduct(vector<int> &nums, int m, int n)
    {
        long long int prod = INT_MIN;
        int negs = 0, i, min = INT_MIN, ind;
        for (i = m; i <= n; i++)
        {
            if (nums[i] < 0)
                negs++;
            if (nums[i] < 0 && nums[i] > min) 
            {
                min = nums[i];
                ind = i;
            }
        }
        if (negs % 2 == 0)
        {
            for (i = m; i <= n; i++)
            {
                if (prod == INT_MIN)
                    prod = 1;
                prod = prod * nums[i];
            }
            return prod;
        }
        vector<long long int> dp(n-m+1, 0);
        dp[0] = nums[m];
        for (i = m+1; i <= n; i++)
        {
            dp[i-m] = dp[i-1-m] * (long long int) nums[i];
        }
        int ans = INT_MIN;
        for (i = m; i <= n; i++)
        {
            if (nums[i] < 0)
            {
                int temp;
                if (n != m)
                    temp = max(dp[i-m], dp[n-m]/dp[i-m]);
                else
                    temp = dp[i-m];
                if (temp > ans)
                    ans = temp;
            }
            if (dp[i-m] > ans)
                ans = dp[i-m];
        }
        return ans;
    }
};
