// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        // odd length substrings
        for (int i = 0; i < n; i++)
        {
            int j = i, k = i;
            while (s[j] == s[k] && j >= 0 && k < n)
            {
               count++;
                j--;
                k++;
            }
        }
        // even length substrings
        for (int i = 0; i < n-1; i++)
        {
            int j = i, k = i+1;
            while (s[j] == s[k] && j >= 0 && k < n)
            {
                count++;
                j--;
                k++;
            }
        }
        return count;
    }
};
