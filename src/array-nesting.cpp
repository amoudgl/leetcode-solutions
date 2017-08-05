// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> visited;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited.find(i) == visited.end())
            {
                visited.insert(i);
                int count = 1, k = i;
                while (nums[k] != i)
                {
                    visited.insert(nums[k]);
                    k = nums[k];
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
