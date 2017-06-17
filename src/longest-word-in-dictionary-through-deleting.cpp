// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        int l = 0, n = s.length();
        string ans;
        for (int i = 0; i < d.size(); i++)
        {
            string word = d[i];
            if (word.length() > l && word.length() <= n && FindString(s, d[i]) == true) 
            {
                l = word.length();
                ans = word;
            }
            else if (word.length() > n) break;
        }
        return ans;
    }
    bool FindString(string a, string b)
    {
        int j = 0, n = b.length();
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[j]) j++;
            if (j == n) return true;
        }
        return false;
    }
};
