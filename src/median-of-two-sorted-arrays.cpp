// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int i;
        for (i = 0; i < nums1.size(); i++)
            a.push_back(nums1[i]);
        for (i = 0; i < nums2.size(); i++)
            a.push_back(nums2[i]);
        sort(a.begin(), a.end());
        int n = a.size();
        if (n % 2 == 1)
            return a[n/2];
        else
            return ((float)a[n/2] + (float)a[n/2-1])/2;
    }
};
