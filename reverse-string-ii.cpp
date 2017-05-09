class Solution {
public:
    string reverseStr(string s, int k) {
        int i, n = s.length();
        for (i = 0; i < n; i += 2*k)
        {
            rev(s, i, k);
        }
        return s;
    }
    void rev(string &s, int i, int k)
    {
        int j;
        if (i + k > s.length())
        {
            j = s.length() - 1;
        }
        else
            j = i + k - 1;
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    
};
