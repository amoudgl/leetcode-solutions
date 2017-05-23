// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool checkRecord(string s) {
        int i, n = s.length(), nabsents = 0, nlate = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'A') nabsents++;
            else if (s[i] == 'L') nlate++;
            if (i-1 >= 0 && s[i-1] == 'L' && s[i] != 'L') nlate = 0;
            
            if (nabsents > 1 || nlate > 2)
                return false;
        }
        return true;
    }
};
