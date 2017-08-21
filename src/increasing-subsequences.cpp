// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        f(nums, 0, v);
        vector<vector<int> > a;
        for (auto x : ans)
            a.push_back(x);
        return a;
    }
    void f(vector<int> &nums, int k, vector<int> v)
    {
        if (k == nums.size())
        {
            if (v.size() >= 2)
            {
                sort(v.begin(), v.end());
                if (ans.find(v) == ans.end())
                    ans.insert(v);
            }
            return;
        }
        else if (v.empty() || nums[k] >= v.back())
        {
            v.push_back(nums[k]);
            f(nums, k+1, v);
            v.pop_back();
        }
        f(nums, k+1, v);
    }
private:
    set<vector<int> > ans;
};
