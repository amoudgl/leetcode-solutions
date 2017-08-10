// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans(2, 0);
        int i = sqrt(area);
        while (i >= 1)
        {
            if (area % i == 0)
            {
                ans[0] = max(area/i, i);
                ans[1] = min(area/i, i);
                break;
            }
            i--;
        }
        return ans;
    }
};
