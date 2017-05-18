// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        if (n == 0)
            return false;
        else if (n == 1)
            return true;
        if (isCapital(word[0]))
        {
            bool check = isCapital(word[1]);
            if (check == true)
            {
                for (int i = 2; i < n; i++)
                {
                    if (!isCapital(word[i]))
                        return false;
                }
                return true;
            }
            else
            {                
                for (int i = 2; i < n; i++)
                {
                    if (isCapital(word[i]))
                        return false;
                }
                return true;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (isCapital(word[i]))
                    return false;
            }
            return true;
        }
        
    }
    bool isCapital(char a)
    {
        if (a >= 'A' && a <= 'Z')
            return true;
        return false;
    }
};
