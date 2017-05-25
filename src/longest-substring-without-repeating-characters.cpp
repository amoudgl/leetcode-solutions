// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, max = 0, j = 0;
        unordered_map<char, int> m;
        for (i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]] = 1;
            }
            else
            {
                while (s[j] != s[i])
                {
                    m.erase(s[j]);
                    j++;
                }
                m.erase(s[j]);
                j++;
                m[s[i]] = 1;
            }
            if (m.size() > max)
                max = m.size();
        }
        return max;
    }
};
