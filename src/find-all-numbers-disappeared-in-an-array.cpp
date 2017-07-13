// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[nums[i]-1] != nums[i])
            {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i+1)
                ans.push_back(i+1);
        }
        return ans;
    }
private:
    void swap(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
};
