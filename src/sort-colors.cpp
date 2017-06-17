// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = 0, k = nums.size()-1;
        while (j <= k)
        {
            if (nums[j] == 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j++;
            }
            else if (nums[j] == 1)
            {
                j++;
            }
            else if (nums[j] == 2)
            {
                int temp = nums[j];
                nums[j] = nums[k];
                nums[k] = temp;
                k--;
            }
        }
    }
};
