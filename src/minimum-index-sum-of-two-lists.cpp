// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        int i; 
        for (i = 0; i < list1.size(); i++)
        {
            m[list1[i]] = i;
        }
        vector<string> ans;
        int minsum = INT_MAX;
        for (i = 0; i < list2.size(); i++)
        {
            if (m.find(list2[i]) != m.end() && m[list2[i]]+i < minsum)
            {
                ans.clear();
                ans.push_back(list2[i]);
                minsum = m[list2[i]]+i;
            }
            else if (m.find(list2[i]) != m.end() && m[list2[i]]+i == minsum)
            {
                ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};
