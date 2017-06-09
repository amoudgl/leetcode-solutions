// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        if (n == 0) return ans;
        ans[0] = bsearchlow(nums, target, 0, n-1);
        ans[1] = bsearchhigh(nums, target, 0, n-1);
        return ans;
    }
    int bsearchlow(vector<int> &nums, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (nums[mid] == target && (mid == 0 || nums[mid-1] != target))
                return mid;
            else if (target <= nums[mid])
                return bsearchlow(nums, target, m, mid-1);
            else if (target > nums[mid])
                return bsearchlow(nums, target, mid+1, n);
        }
        return -1;
    }
    int bsearchhigh(vector<int> &nums, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (nums[mid] == target && (mid == nums.size()-1 || nums[mid+1] != target))
                return mid;
            else if (target < nums[mid])
                return bsearchhigh(nums, target, m, mid-1);
            else if (target >= nums[mid])
                return bsearchhigh(nums, target, mid+1, n);            
        }
        return -1;
    }
};
