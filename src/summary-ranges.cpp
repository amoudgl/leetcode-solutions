// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start = 0, i = 1;
        vector<string> ans;
        if (nums.size() == 0) return ans;
        for (i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] == INT_MAX || nums[i-1]+1 != nums[i])
            {
                if (i-start > 1) ans.push_back(to_string(nums[start]) +
                                                "->" + to_string(nums[i-1]));
                else ans.push_back(to_string(nums[start]));
                start = i;
            }
        }
        if (i-start > 1) ans.push_back(to_string(nums[start]) +
                                        "->" + to_string(nums[i-1]));
        else ans.push_back(to_string(nums[start]));      
        return ans;
    }
};
