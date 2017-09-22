// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    static bool cmpx(const Point a, Point b)
    {
        if (a.x == b.x)
            return a.y < b.y;
        else 
            return a.x < b.x;
    }
    static bool cmpy(const Point a, Point b)
    {
        if (a.y == b.y)
            return a.x < b.x;
        else 
            return a.y < b.y;
    }    
    int gcd(int a, int b)
    {
        if (b == 0) return a;
        else return gcd(b, a%b);
    }
    int maxPoints(vector<Point>& points) {
        unordered_map<string, unordered_set<int> > m;
        int ans1 = 0, ans2 = 0, ans3 = 0;
        int prevx, prevy, countx, county;
        sort(points.begin(), points.end(), cmpx);
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i+1; j < points.size(); j++)
            {
                int x1 = points[i].x;
                int x2 = points[j].x;
                int y1 = points[i].y;
                int y2 = points[j].y;
                if ((y2-y1) != 0 && (x2-x1) != 0)
                {
                    int m1 = abs(y2-y1);
                    int m2 = abs(x2-x1);
                    int g = gcd(m1, m2);
                    m1 = m1/g;
                    m2 = m2/g;
                    if (((y2-y1) > 0 && (x2-x1) < 0) || ((y2-y1) < 0 && (x2-x1) > 0))
                        m1 = -m1;
                    int c1 = m2*y1 - m1*x1;
                    int c2 = m2;
                    int sign = 1;
                    if (c1 == 0) c2 = 1;
                    else 
                    {
                        if (c1 < 0) sign = -1;
                        g = gcd(abs(c1), abs(c2));
                        c1 = sign*(c1/g);
                        c2 = c2/g;
                    }
                    string x = to_string(m1) + "," + to_string(m2) + "," + to_string(c1) + "," + to_string(c2);
                    if (m.find(x) == m.end())
                    {
                        unordered_set<int> s;
                        m[x] = s;
                    }                        
                    m[x].insert(i);
                    m[x].insert(j);
                }
            }
            if (i == 0)
            {
                prevx = points[i].x;
                countx = 1;
            }
            else
            {
                if (points[i].x == prevx) countx++;
                else
                {
                    ans2 = max(ans2, countx);
                    countx = 1;
                    prevx = points[i].x;
                }
            }
            ans2 = max(ans2, countx);
        }
        for (auto x : m)
        {
            int sz = x.second.size();
            ans1 = max(ans1, sz);
        }   
        sort(points.begin(), points.end(), cmpy);
        for (int i = 0; i < points.size(); i++)
        {
            if (i == 0)
            {
                prevy = points[i].y;
                county = 1;
            }
            else
            {
                if (points[i].y == prevy) county++;
                else
                {
                    ans3 = max(ans3, county);
                    county = 1;
                    prevy = points[i].y;
                }
            }
            ans3 = max(ans3, county);
        }
        return max(ans1, max(ans2, ans3));
    }
};
