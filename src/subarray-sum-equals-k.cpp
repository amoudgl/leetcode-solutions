// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long int, long long int> m;
        long long int sum = 0, K = k;
        m[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (long long int) nums[i];
            if (m.find(sum-k) != m.end()) ans += m[sum-k];
            if (m.find(sum) == m.end()) m[sum] = 1;
            else m[sum]++;
        }
        return ans;
    }
};
