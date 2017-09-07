// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int x = 1;
        bool f = false;
        int i = 0;
        vector<int> ans = {1};
        while (i < k-1)
        {
            if (!f) x = n+1-x;
            else x = n+2-x;
            ans.push_back(x);
            f = !f;
            i++;
        }
        while (ans.size() < n)
        {
            if (!f) x++;
            else x--;
            ans.push_back(x);
        }
        return ans;
    }
};
