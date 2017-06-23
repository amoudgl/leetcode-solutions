// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() > b.length())  return a.length();
        else if (a.length() < b.length()) return b.length();
        else if (a.length() == b.length() && a != b) return a.length();
        else return -1;
    }
};
