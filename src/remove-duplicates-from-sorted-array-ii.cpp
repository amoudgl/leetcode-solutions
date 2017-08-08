// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int l = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i-1] && l == 2)
            {
                int k = nums[i]; l = 1;
                while (nums[i] == k && nums.size() > i)
                    nums.erase(nums.begin()+i);
            }
            else if (i > 0 && nums[i] == nums[i-1]) l++;
            else if (i > 0 && nums[i] != nums[i-1]) l = 1;
        }
        return nums.size();
    }
};
