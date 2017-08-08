// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty() || s2.empty()) return false;
        unordered_map<char, int> set1;
        unordered_map<char, int> set2;
        for (char c : s1)
        {
            if (set1.find(c) == set1.end()) set1[c] = 1;
            else set1[c]++;
        }
        int l = s1.length(), n = s2.length();
        for (int i = 0; i < n-l+1; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < l; j++)
                {
                    if (set2.find(s2[j]) == set2.end()) set2[s2[j]] = 1;
                    else set2[s2[j]]++;
                }
            }
            else
            {
                set2[s2[i-1]]--;
                if (set2[s2[i-1]] == 0) set2.erase(s2[i-1]);
                if (set2.find(s2[i+l-1]) == set2.end()) set2[s2[i+l-1]] = 1;
                else set2[s2[i+l-1]]++;
            }
            if (set1 == set2) return true;
        }
        return false;
    }
};
