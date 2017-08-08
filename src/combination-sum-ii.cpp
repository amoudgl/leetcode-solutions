// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        f(candidates, 0, target, 0, v);
        vector<vector<int> > ans;
        for (auto v : s) ans.push_back(v);
        return ans;
    }
    void f(vector<int>& candidates, int k, int target, int sum, vector<int> v)
    {
        if (target == sum)
        {
            sort(v.begin(), v.end());
            if (s.find(v) == s.end()) s.insert(v);
            return;
        }
        if (k == candidates.size() || sum > target) return;
        v.push_back(candidates[k]);
        f(candidates, k+1, target, sum+candidates[k], v);
        v.pop_back();
        f(candidates, k+1, target, sum, v);
    }
private:
    set<vector<int> > s;
};
