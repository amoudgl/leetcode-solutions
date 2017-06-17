// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(); 
        if (n == 0) return 0;
        sort(citations.begin(), citations.end());
        int maxh = 0;
        for (int i = 0; i < n; i++)
        {
            int h = n-i;
            if (citations[i] >= h && h > maxh)
                maxh = h;
        }
        return maxh;
    }
};
