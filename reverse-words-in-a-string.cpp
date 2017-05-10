class Solution {
public:
    void reverseWords(string &s) {
        int i;
        string word, ans;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
                word += s[i];
            else if (s[i] == ' ' && !word.empty())
            {
                rev(word);
                if (ans.length() == 0)
                    ans += word;
                else
                    ans += (' ' + word);
                word.clear();
            }
        }
        if (!word.empty())
        {
            rev(word);
            if (ans.length() == 0)
                ans += word;
            else
                ans += (' ' + word);
            word.clear();
        }
        rev(ans);
        s = ans;
        ans.clear();
    }
    void rev(string &s)
    {
        int i = 0, j = s.length()-1;
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
