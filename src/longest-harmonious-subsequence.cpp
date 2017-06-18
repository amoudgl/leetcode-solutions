// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m.find(nums[i]) == m.end() ? m[nums[i]] = 1 : m[nums[i]]++;
        }
        int ans = 0;
        for (auto p : m)
        {
            int l = 0;
            if (m.find(p.first+1) != m.end())
                l = p.second + m[p.first+1];
            ans = max(ans, l); 
        }
        return ans;
    }
};
