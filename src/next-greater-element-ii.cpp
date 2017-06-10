// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int, int> > s;
        int last, n = nums.size();
        unordered_map<int, int> m;
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                while (!s.empty() && s.top().first < nums[i])
                {
                    if (m.find(s.top().second) == m.end())
                    {
                        m[s.top().second] = nums[i];
                    }
                    s.pop();
                }
                s.push(make_pair(nums[i], i));
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (m.find(i) == m.end()) ans.push_back(-1);
            else 
                ans.push_back(m[i]);
        }
        return ans;
    }
};
