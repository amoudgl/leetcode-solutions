struct C
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int, int>, C> s;
        int n = nums.size(), mindiff = INT_MAX;
        vector<int> ans(2, 0);
        if (n == 1)
        {
            return vector<int> {nums[0][0], nums[0][0]};
        }
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++)
        {
            s.insert(make_pair(nums[i][0], i));
        }
        while (1)
        {
            auto start = s.begin();
            auto end = s.rbegin();
            if (abs(end->first - start->first) < mindiff)
            {
                mindiff = abs(end->first - start->first);
                ans[0] = start->first;
                ans[1] = end->first;
            }
            int ind = start->second;
            int val = start->first;
            if (p[ind]+1 >= nums[ind].size()) break;
            p[ind]++;
            s.erase(make_pair(val, ind));
            s.insert(make_pair(nums[ind][p[ind]], ind));
        }
        return ans;
    }
};
