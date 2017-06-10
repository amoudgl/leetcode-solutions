// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int i;
        stack<int> s;
        unordered_map<int, int> m;
        for (i = 0; i < nums.size(); i++)
        {
            while (!s.empty() && s.top() < nums[i])
            {
                m[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        vector<int> ans;
        for (i = 0; i < findNums.size(); i++)
        {
            if (m.find(findNums[i]) == m.end()) ans.push_back(-1);
            else ans.push_back(m[findNums[i]]);
        }
        return ans;
    }
};
