// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        N = n; K = k;
        vector<int> v;
        f(1, v);
        return ans;
    }
    void f(int n, vector<int> v)
    {
        if (n > N || v.size() > K) return;
        v.push_back(n);
        if (v.size() == K) ans.push_back(v);
        else f(n+1, v);
        v.pop_back();
        f(n+1, v);
    }
private:
    vector<vector<int>> ans;
    int N, K;
};
