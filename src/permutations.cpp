// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        GeneratePermutations(ans, nums, 0, nums.size()-1);
        return ans;
    }
    void GeneratePermutations(vector<vector<int>> &ans, vector<int> nums, int m, int n)
    {
        if (m == n)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = m; i <= n; i++)
        {
            int temp = nums[i];
            nums[i] = nums[m];
            nums[m] = temp;
            GeneratePermutations(ans, nums, m+1, n);
        }
    }
};
