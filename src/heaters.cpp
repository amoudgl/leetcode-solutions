// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), ans = 0, m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < n; i++)
        {
            int i1 = lowerbound(heaters, houses[i], 0, m-1);
            int i2 = upperbound(heaters, houses[i], 0, m-1);
            i1 = max(0, i1);
            i2 = min(i2, m-1);
            int dist = min(abs(heaters[i1]-houses[i]), abs(heaters[i2]-houses[i]));
            ans = max(ans, dist);
        }
        return ans;
    }
    int lowerbound(vector<int>& heaters, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (target == heaters[mid])
                return mid;
            else if (target > heaters[mid])
                return lowerbound(heaters, target, mid+1, n);
            else if (target < heaters[mid])
                return lowerbound(heaters, target, m, mid-1);
        }
        return n;
    }
    int upperbound(vector<int>& heaters, int target, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            if (target == heaters[mid])
                return mid;
            else if (target > heaters[mid])
                return upperbound(heaters, target, mid+1, n);
            else if (target < heaters[mid])
                return upperbound(heaters, target, m, mid-1);
        }
        return m;
    }
};
