// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, n_zeros = 0, n_ones = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) n_zeros++;
            else if (nums[i] == 1) n_ones++;
            int diff = n_zeros - n_ones;
            if (diff != 0 && m.find(diff) == m.end()) m[diff] = i;
            if (m.find(diff) != m.end()) ans = max(ans, i-m[diff]); 
            if (diff == 0) ans = max(ans, i+1);
        }
        return ans;
    }
};
