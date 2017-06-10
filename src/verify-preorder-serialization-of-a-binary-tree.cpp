// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;
        string str;
        if (preorder.length() == 0) return false;
        else if (preorder == "#") return true;
        for (int i = 0; i < preorder.length(); i++)
        {
            if (preorder[i] == ',')
            {
                if (str == "#")
                {
                    if (s.empty()) return false;
                    while (!s.empty() && s.top() == "#")
                    {
                        s.pop();
                        if (s.empty()) 
                            return false;
                        else
                            s.pop();
                    }
                    s.push("#");
                }
                else
                    s.push(str);
                str.clear();
            }
            else
                str += preorder[i];
        }
        if (str == "#")
        {
            if (s.empty()) return false;
            while (!s.empty() && s.top() == "#")
            {
                s.pop();
                if (s.empty()) 
                    return false;
                else
                    s.pop();
            }
        }
        else
            s.push(str);
        if (!s.empty()) return false;
        return true;
    }
};
