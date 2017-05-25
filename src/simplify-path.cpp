// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string word;
        for (int i = 1; i < path.length(); i++)
        {
            if (path[i] == 47 && path[i-1] != 47)
            {
                if (word.length() == 2 && word[0] == 46 && word[1] == 46)
                {
                    if (!s.empty())
                        s.pop();
                }
                else if (word.length() > 0 && word != ".")
                    s.push(word);
                word.clear();
            }
            else if (path[i] != 47)
                word += path[i];
        }
        if (word.length() == 2 && word[0] == 46 && word[1] == 46)
        {
            if (!s.empty())
                s.pop();
        }
        else if (word.length() > 0 && word != ".")
            s.push(word);   

       path = "";
       if (s.empty())
       {
           path += "/";
           return path;
       }
       while (!s.empty())
       {
           path = "/" + s.top() + path;
           s.pop();
       }
       return path;
    }
};
