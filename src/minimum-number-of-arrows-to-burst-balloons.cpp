// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end());
        int minE = INT_MIN, count = 0, maxS = INT_MIN;
        for (int i = 0; i < points.size(); i++)
        {
            if (count == 0 || points[i].first > minE)
            {
                count++;
                minE = points[i].second;
                maxS = points[i].first;
            }
            else 
            {
                maxS = max(maxS, points[i].first);
                minE = min(minE, points[i].second);
            }              
        }
        return count;
    }
};
