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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return vector<int> ();
        vector<pair<int, int> > sorted(n, pair<int, int> (0, 0));
        unordered_map<string, int> m;        
        for (int i = 0; i < intervals.size(); i++)
        {
            sorted[i].first = intervals[i].start;
            sorted[i].second = intervals[i].end;
            string s = GetString(intervals[i].start, intervals[i].end);
            m[s] = i;
        }
        sort(sorted.begin(), sorted.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int temp = bsearch(sorted, sorted[i].second, 0, n-1);
            ans[m[GetString(sorted[i].first, sorted[i].second)]] = 
                (temp >= 0 ? m[GetString(sorted[temp].first, sorted[temp].second)] : -1); 
            
        }
        return ans;
    }
    int bsearch(vector<pair<int, int>> &intervals, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (target == intervals[mid].first)
                return mid;
            else if (target > intervals[mid].first)
                return bsearch(intervals, target, mid+1, n);
            else if (target < intervals[mid].first)
                return bsearch(intervals, target, m, mid-1);
        }
        if (m == 0 || m == intervals.size()) return -1;
        return m;
    }
    string GetString(int i, int j)
    {
        string s;
        s = to_string(i) + " " + to_string(j);
        return s;
    }
};
