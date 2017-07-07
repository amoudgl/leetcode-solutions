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
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int flag = 0;
        for (auto p : s)
        {
            int x1 = p.first;
            int x2 = p.second;
            if (val >= x1 && val <= x2)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            if (s.size() == 0 || (s.find(val+1) == s.end() && e.find(val-1) == e.end()))
            {
                s[val] = val;
                e[val] = val;
            }
            else if (e.find(val-1) != e.end() && s.find(val+1) != s.end())
            {
                int x1 = e[val-1];
                int x2 = s[val+1];
                e.erase(val-1);
                s.erase(x1);
                e.erase(x2);
                s.erase(val+1);
                s[x1] = x2;
                e[x2] = x1;
            }
            else if (e.find(val-1) != e.end() && s.find(val+1) == s.end())
            {
                int x1 = e[val-1];
                e.erase(val-1);
                s[x1] = val;
                e[val] = x1;
            }
            else if (s.find(val+1) != s.end() && e.find(val-1) == e.end())
            {
                int x1 = s[val+1];
                s.erase(val+1);
                s[val] = x1;
                e[x1] = val;
            }  
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto p : s)
        {
            Interval i(p.first, p.second);
            ans.push_back(i);
        }
        return ans;
    }
private:
    map<int, int> s;
    map<int, int> e;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
