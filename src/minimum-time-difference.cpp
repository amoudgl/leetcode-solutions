// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> points(1440, 0);
        for (int i = 0; i < timePoints.size(); i++)
        {
            auto p = parse(timePoints[i]);
            points[60*p.first+p.second]++;
        }
        int ans = INT_MAX, prev = -1, first;
        for (int i = 0; i < points.size(); i++)
        {
            if (points[i] > 1) return 0;
            if (prev == -1 && points[i] > 0)
            {
                prev = i;
                first = i;
            }
            else if (points[i] > 0)
            {
                int mintime = min(i-prev, 1440-i+first);
                ans = min(ans, mintime);
                prev = i;
            }
        }
        return ans;
    }
private: 
    pair<int, int> parse(string s)
    {
        int i = 0;
        while (i < s.size() && s[i] != ':') i++;
        int h = stoi(s.substr(0, i));
        int m = stoi(s.substr(i+1,s.size()-i));
        return make_pair(h, m);
    }
};
