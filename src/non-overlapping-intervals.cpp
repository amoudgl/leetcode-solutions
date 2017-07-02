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
    static bool cmp(Interval i, Interval j)
    {
        return i.start < j.start;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0, mine = INT_MIN; 
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i].start >= mine)
            {
                mine = intervals[i].end;
            }
            else 
            {
                count++;
                mine = min(intervals[i].end, mine);
            }
        }
        return count;
    }
};
