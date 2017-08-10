// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first >= b.first;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<string> ();
        vector<string> ans(n);
        vector<pair<int, int> > a;
        for (int i = 0; i < n; i++)
        {
            a.push_back(make_pair(nums[i], i));
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (i == 0) ans[a[i].second] = "Gold Medal";
            else if (i == 1) ans[a[i].second] = "Silver Medal";
            else if (i == 2) ans[a[i].second] = "Bronze Medal";
            else ans[a[i].second] = to_string(i+1);
        }
        return ans;
    }
};
