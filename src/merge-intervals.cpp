// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    vector<pair<int, int> > a;
    if (intervals.empty()) return intervals;
    for (int i = 0; i < intervals.size(); i++)
    {
        a.push_back(make_pair(intervals[i].start, intervals[i].end));
    }
    sort(a.begin(), a.end());
    vector<Interval> ans;
    ans.push_back(Interval(a[0].first, a[0].second));
    int j = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (ans[j].end >= a[i].first && ans[j].end < a[i].second)
        {
            ans[j].end = a[i].second;
        }
        else if (ans[j].end < a[i].first)
        {
            ans.push_back(Interval(a[i].first, a[i].second));
            j++;
        }
    }
    return ans;
    }
};
