// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int> > a;
        if (arrays.size() == 0) return 0;
        for (int i = 0; i < arrays.size(); i++)
        {
            int arraymin = INT_MAX;
            int arraymax = INT_MIN;
            for (auto j : arrays[i])
            {
                if (j < arraymin) arraymin = j;
                if (j > arraymax) arraymax = j;
            }
            a.push_back(make_pair(arraymin, arraymax));
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i+1; j < a.size(); j++)
            {
                int min1 = a[i].first;
                int max1 = a[i].second;
                int min2 = a[j].first;
                int max2 = a[j].second;
                int dist = max(abs(max1-max2), max(abs(max1-min2), max(abs(min1-min2), abs(min1-max2))));
                if (dist > ans) ans = dist;
            }
        }
        return ans;
    }
};
