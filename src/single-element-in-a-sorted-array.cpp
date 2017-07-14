// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        return bsearch(nums, 0, n);
    }
    int bsearch(vector<int>& nums, int m, int n)
    {
        if (m <= n)
        {
            int mid = m + (n-m)/2;
            int size = nums.size();
            if ((n-m+1) == 1 || (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]))
            {
                return nums[mid];
            }
            else if (nums[mid] == nums[mid+1])
            {
                int remain = (n-m+1)-mid-2;
                if (remain % 2 == 0) return bsearch(nums, m, mid-1);
                else return bsearch(nums, mid+2, n);
            }
            else if (nums[mid] == nums[mid-1])
            {
                int remain = (n-m+1)-mid-1;
                if (remain % 2 == 0) return bsearch(nums, m, mid-2);
                else return bsearch(nums, mid+1, n);
            }
        }
        return -1;
    }
};
