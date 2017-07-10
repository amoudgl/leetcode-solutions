// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unordered_set<string> s;
        sort(nums.begin(), nums.end());
        int j, k, n = nums.size(), mindiff = INT_MAX, count = 0, ans;        
        for (int i = 1; i < nums.size(); i++)
        {
            j = i-1;
            k = i+1;
            if (nums[i] != nums[i-1]) count = 0;
            else if (nums[i] == nums[i-1]) count++;
            if (count < 2)
            {
                while (j >= 0 && k < n)
                {
                    long long int sum = nums[i] + nums[j] + nums[k];
                    long long int diff = abs(target-sum);
                    if (diff < mindiff)
                    {
                        ans = sum;
                        mindiff = diff;
                    }
                    if (sum > target) j--;
                    else if (sum < target) k++;
                    else if (sum == target)
                    {
                        return target;
                    }
                }                
            }
        }
        return ans;
    }
};
