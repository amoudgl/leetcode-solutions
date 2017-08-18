// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int > > v;
        for (int n : arr)
            v.push_back(make_pair(abs(x-n), n));   
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
