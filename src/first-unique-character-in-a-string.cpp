// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end() && s[i] != ' ') m[s[i]] = 1;
            else if (s[i] != ' ') m[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && m[s[i]] == 1) return i;
        }
        return -1;
    }
};
