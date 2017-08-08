// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        f(nums, 0, v);
        vector<vector<int> > ans;
        for (auto v : s) ans.push_back(v);
        s.clear();
        return ans;
    }
    void f(vector<int>& nums, int k, vector<int> v)
    {
        if (v.size() > 0) sort(v.begin(), v.end());
        if (s.find(v) == s.end()) s.insert(v);
        if (k == nums.size()) return;
        v.push_back(nums[k]);
        f(nums, k+1, v);
        v.pop_back();
        f(nums, k+1, v);   
    }
private:
    unordered_set<vector<int>, VectorHash > s;
};
