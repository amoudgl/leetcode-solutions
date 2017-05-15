// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        int count = 0, n = candies.size();
        for (int i = 0; i < n; i++)
        {
            if (m.find(candies[i]) == m.end())
            {
                count++;
                m[candies[i]] = 1;
            }
        }
        return min(count, n/2);
    }
};
