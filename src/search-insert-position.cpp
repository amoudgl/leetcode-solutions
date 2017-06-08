// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return bsearch(nums, target, 0, n-1);
    }
    int bsearch(vector<int> &nums, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m + (n-m)/2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                return bsearch(nums, target, mid+1, n);
            else if (target < nums[mid])
                return bsearch(nums, target, m, mid-1);
        }
        else 
            return m;
    }
};
