// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        for (int k = 0; k < moves.length(); k++)
        {
            char c = moves[k];
            if (c == 'U') i--;
            else if (c == 'D') i++;
            else if (c == 'L') j--;
            else if (c == 'R') j++;
        }
        if (i == 0 && j == 0) return true;
        return false;
    }
};
