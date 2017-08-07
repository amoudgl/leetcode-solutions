// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (d(p1, p2) == 0 || d(p1, p3) == 0 || d(p3, p4) == 0 || d(p1, p4) == 0 || d(p2, p3) == 0|| d(p2, p4) == 0)
            return false;
        
        if ((d(p1, p2) == d(p1, p3) && d(p2, p4) == d(p3, p4) && d(p1, p2) == d(p2, p4) && 
           d(p1, p2)+d(p2, p4) == d(p1, p4) &&  d(p1, p3)+d(p3, p4) == d(p1, p4)) || 
           (d(p1, p3) == d(p1, p4) && d(p2, p3) == d(p2, p4) && d(p1, p3) == d(p2, p3) && 
                d(p1, p3)+d(p2, p3) == d(p1, p2) && d(p1, p4)+d(p2, p4) == d(p1, p2)) || 
           (d(p1, p2) == d(p1, p4) && d(p2, p3) == d(p3, p4) && d(p1, p2) == d(p2, p3) && 
                d(p1, p2)+d(p2, p3) == d(p1, p3) &&  d(p1, p4)+d(p3, p4) == d(p1, p3))) 
        {
            return true;
        }
        return false;
    }
    int d(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }
};
