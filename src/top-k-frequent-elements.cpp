// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
        }
        priority_queue<pair<int, int>> heap;
        for (auto p : m)
        {
            if (heap.size() < k)
                heap.push(make_pair(-1*p.second, p.first));
            else if (abs(heap.top().first) <= p.second)
            {
                heap.pop();
                heap.push(make_pair(-p.second, p.first));
            }
        }
        vector<int> ans;
        while (!heap.empty())
        {
            auto p = heap.top();
            ans.push_back(p.second);
            heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
