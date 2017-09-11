// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ip;
        f(0, s, ip);
        vector<string> ret;
        for (auto s : ans) ret.push_back(s);
        return ret;
    }
    void f(int i, string s, vector<string> &ip)
    {
        if (ip.size() > 4) return;
        if (i >= s.length())
        {
            if (ip.size() == 4)
            {
                string x;
                for (int i = 0; i < 3; i++) x += (ip[i] + ".");
                x += ip[3];
                ans.insert(x);
            }
            return;
        }        
        int x = stoi(s.substr(i, 3));
        int y = stoi(s.substr(i, 2));
        int z = stoi(s.substr(i, 1));
        if (x <= 255 && to_string(x) == s.substr(i, 3))
        {
            ip.push_back(s.substr(i, 3));
            f(i+3, s, ip);
            ip.pop_back();
        }
        if (y <= 255 && to_string(y) == s.substr(i, 2))
        {
            ip.push_back(s.substr(i, 2));
            f(i+2, s, ip);
            ip.pop_back();
        }
        if (z <= 255 && to_string(z) == s.substr(i, 1))
        {
            ip.push_back(s.substr(i, 1));
            f(i+1, s, ip);
            ip.pop_back();
        }
    }
private:
    unordered_set<string> ans;
};
