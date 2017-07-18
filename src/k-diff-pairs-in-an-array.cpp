// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<long long int, int> m;
        int count = 0;
        long long int K = k;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto p : m)
        {
            long long int x = p.first;
            long long int y = p.second;
            if (K == 0 && y > 1) count++;
            else if (K != 0 && m.find(x + K) != m.end()) count++;
        }
        return count;
    }
};
