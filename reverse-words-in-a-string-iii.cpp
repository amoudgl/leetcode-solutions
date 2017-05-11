class Solution {
public:
    string reverseWords(string s) {
        int i;
        string word, ans;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && i > 0 && s[i-1] != ' ')
            {
                rev(word);
                if (ans.empty())
                    ans += word;
                else
                    ans += " " + word;
                word.clear();
            }
            else if (s[i] != ' ')
                word += s[i];
        }
        if (!word.empty())
        {
            rev(word);
            if (ans.empty())
                ans += word;
            else
                ans += " " + word;
            word.clear();
        }
        return ans;
    }
    void rev(string &word)
    {
        int i = 0, j = word.length()-1;
        while (i < j)
        {
            char temp = word[i];
            word[i] = word[j];
            word[j] = temp;
            i++;
            j--;
        }
    }
};
