// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(); 
        int m = s.size();
        if (m == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i, j = 0;
        for (i = 0; i < n; i++)
        {
            if (g[i] <= s[j])
            {
                count++;
                j++;
            }
            else if (g[i] > s[j])
            {
                while (j < m && g[i] > s[j])
                {
                    j++;
                }
                if (j == m)
                    break;
                else if (g[i] <= s[j])
                {
                    count++;
                    j++;
                }
            }
            if (j == m)
                break;
        }
        return count;
    }
};
