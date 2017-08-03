// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            a.push_back(make_pair(nums[i], i));
        }
        sort(a.begin(), a.end());
    }
    static bool cmp(const pair<int, int> &l,const pair<int, int> &r)
    {
        return l.first < r.first;
    }
    int pick(int target) {
        auto l = lower_bound(a.begin(), a.end(), pair<int, int> (target, 0), cmp) - a.begin();
        auto h = upper_bound(a.begin(), a.end(), pair<int, int> (target, 0), cmp) - a.begin();
        h--;
        int range = h-l+1;
        int ind = rand()%range + l;
        return a[ind].second;
    }
private:
    vector<pair<int, int> > a;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
