// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        for (int i = 0; i + 9 < s.length(); i++)
        {
            string sub = s.substr(i, 10);
            if (m.find(sub) == m.end()) m[sub] = 1;
            else m[sub]++;
        }
        vector<string> ans;
        for (auto p : m)
        {
            if (p.second > 1) ans.push_back(p.first);
        }
        return ans;
    }
};
