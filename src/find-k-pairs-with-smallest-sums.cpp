// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int flag = 0;
        priority_queue<pair<int, pair<int, int> > > maxheap;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (maxheap.size() < k)
                    maxheap.push(make_pair(nums1[i]+nums2[j], make_pair(nums1[i], nums2[j])));
                else if (maxheap.size() == k && maxheap.top().first > nums1[i]+nums2[j])
                {
                    maxheap.pop();
                    maxheap.push(make_pair(nums1[i]+nums2[j], make_pair(nums1[i], nums2[j])));
                }
                else if (maxheap.size() == k && maxheap.top().first <= nums1[i]+nums2[j])
                    break;
            }
        }
        vector<pair<int, int> > ans;
        while (!maxheap.empty())
        {
            auto p = maxheap.top();
            ans.push_back(p.second);
            maxheap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
