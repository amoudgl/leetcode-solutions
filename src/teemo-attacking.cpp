// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0, s = -1;
        for (int time : timeSeries)
        {
            if (time+duration-1 > s)
            {
                if (s >= time)
                    ans += time+duration-1-s;
                else 
                    ans += duration;
                s = time+duration-1;
            }
        }
        return ans;
    }
};
