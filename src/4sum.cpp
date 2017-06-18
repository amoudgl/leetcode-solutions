// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int> > > m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int sum = nums[i]+nums[j];
                m[sum].push_back(make_pair(i, j));
            }
        }
        vector<vector<int> > ans;
        unordered_set<string> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int remain = target-(nums[i]+nums[j]);
                if (m.find(remain) != m.end())
                {
                    for (int k = 0; k < m[remain].size(); k++)
                    {
                        if (m[remain][k].first != i && m[remain][k].second != j &&
                            m[remain][k].first != j && m[remain][k].second != i)
                        {
                            vector<int> v;
                            v.push_back(nums[i]);
                            v.push_back(nums[j]);
                            v.push_back(nums[m[remain][k].first]);
                            v.push_back(nums[m[remain][k].second]);
                            sort(v.begin(), v.end());
                            if (s.find(ToString(v)) == s.end())
                            {
                                ans.push_back(v);
                                s.insert(ToString(v));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    string ToString(vector<int> &a)
    {
        string s;
        for (int i = 0; i < a.size(); i++)
            s += to_string(a[i]);
        return s;
    }
};
