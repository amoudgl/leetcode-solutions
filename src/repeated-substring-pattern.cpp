// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i, l, n = s.length(), flag = 0;
        for (l = 1; l <= n/2; l++)
        {
            string str = s.substr(0, l);
            flag = 0;
            for (i = 0; i < n; i += l)
            {
                if (i+l-1 >= n)
                {
                    flag = 1;
                    break;
                }
                string test = s.substr(i, l);
                if (test != str)
                {
                    flag = 1;
                    break;
                }

            }
            if (!flag)
                return true;
        }
        return false;
    }
};
