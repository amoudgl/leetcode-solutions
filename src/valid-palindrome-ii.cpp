// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0; 
        int j = s.length()-1;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                string x = s;
                string y = s;
                x.erase(i, 1);
                if (check(x)) return true;
                y.erase(j, 1);
                if (check(y)) return true;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool check(string s)
    {
        int i = 0;
        int j = s.length()-1;
        while (i < j)
        {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
