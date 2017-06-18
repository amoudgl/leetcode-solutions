// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<long long int, long long int> s;
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j && s.find(FindDistance(points, i, j)) != s.end())
                {
                    ans += 2*s[FindDistance(points, i,j)];
                    s[FindDistance(points, i,j)]++;
                }
                else if (i != j && s.find(FindDistance(points, i, j)) == s.end())
                    s[FindDistance(points, i, j)] = 1;
            }
            s.clear();
        }
        return ans;
    }
    long long int FindDistance(vector<pair<int, int>>& points, int i, int j)
    {
        long long int x1 = points[i].first;
        long long int y1 = points[i].second;
        long long int x2 = points[j].first;
        long long int y2 = points[j].second;
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    }
};
