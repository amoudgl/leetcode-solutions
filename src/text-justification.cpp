// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int left = maxWidth;
        vector<string> line;
        for (int i = 0; i < words.size(); i++)
        {
            
            if (line.empty())
            {
                line.push_back(words[i]);
                left -= words[i].length();
            }
            else if (!line.empty())
            {
                int x = words[i].length(); 
                if (left-(x+1) < 0)
                {
                    int j = 0, n = line.size();
                    while (left > 0)
                    {
                        if (j > 0 && n > 1) {line[j] = " " + line[j]; left -= 1;}
                        else if (n == 1) {line[j] = line[j] + " "; left -= 1;}
                        j = (j+1) % n;
                    }
                    string l;
                    for (auto s : line) l += s;
                    ans.push_back(l);
                    line = vector<string> ();
                    left = maxWidth-x;
                    line.push_back(words[i]);
                }
                else if (left-(x+1) > 0)
                {
                    string word = " " + words[i];
                    line.push_back(word);
                    left -= (1+words[i].length());
                }
                else if (left-(x+1) == 0)
                {
                    string word = " " + words[i];
                    line.push_back(word);
                    string l;
                    for (auto s : line) l += s;
                    ans.push_back(l);
                    line = vector<string> ();
                    left = maxWidth;
                }
            }
        }
        if (!line.empty())
        {
            string l;
            for (auto s : line) l += s;
            while (left > 0) {l += " "; left -= 1;}
            ans.push_back(l);
        }
        return ans;
    }
};
