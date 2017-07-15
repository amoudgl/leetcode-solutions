// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> m;
        for (auto word : words)
        {
            int mask = 0, l = word.size();
            for (auto ch : word)
                mask = mask | 1 << (ch-'a');
            m[mask] = max(m[mask], l);
        }
        int ans = 0;
        for (auto x : m)
        {
            for (auto y : m)
            {
                if (!(x.first & y.first)) ans = max(ans, m[x.first]*m[y.first]);
            }
        }
        return ans;
    }
};
