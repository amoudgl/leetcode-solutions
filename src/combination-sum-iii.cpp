// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45) return ans;
        unordered_set<int> s;
        find(n, k, s, 1);
        return ans;
    }
    void find(int sum, int n, unordered_set<int> s, int k)
    {
        if (sum == 0 && n == 0 && !s.empty())
        {
            vector<int> a;
            for (auto p : s) a.push_back(p);
            ans.push_back(a);
            return;
        }
        else if (sum < 0 || n < 0 || k > 9) return;
        for (int i = k; i <= 9; i++)
        {
            if (s.find(i) == s.end())
            {
                s.insert(i);
                find(sum-i, n-1, s, i+1);
                s.erase(i);
            }
        }
    }
private:
    vector<vector<int> > ans;
};
