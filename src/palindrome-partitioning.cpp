// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        if (s.empty())
        {
            ans.push_back(v);
            return ans;
        }
        string prev = "";
        f(s, 0, prev, v);
        return ans;
    }
    void f(string s, int k, string prev, vector<string> v)
    {
        if (k == s.length())
        {
            if (!prev.empty() && check(prev) == true)
            {
                v.push_back(prev);
                ans.push_back(v);
            }
            return;
        }
        if (!prev.empty() && check(prev))
        {
            v.push_back(prev);
            string x(1, s[k]);
            f(s, k+1, x, v);  
            v.pop_back();
        }
        prev += s[k];
        f(s, k+1, prev, v);
    }
    bool check(string s)
    {
        string x = s;
        reverse(x.begin(), x.end());
        if (x == s) return true;
        else return false;
    }
private:
    vector<vector<string> > ans;
};
