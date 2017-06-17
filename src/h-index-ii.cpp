// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int hIndex(vector<int>& citations) {
        return bsearch(citations, 0, citations.size()-1);
    }
    int bsearch(vector<int>& citations, int m, int n)
    {
        if (m <= n)
        {
            int mid = m+(n-m)/2;
            int sz = citations.size();
            int h = sz-mid;
            if (citations[mid] >= h && citations[mid-1] < h)
                return h;
            else if (citations[mid] >= h && citations[mid-1] >= h)
                return bsearch(citations, m, mid-1);
            else if (citations[mid] < h)
                return bsearch(citations, mid+1, n);
        }
        return citations.size()-m;
    }
};
