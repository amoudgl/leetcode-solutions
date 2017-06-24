// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m;
        int maxlength = 0;
        vector<pair<int, string> > v;
        unordered_map<string, bool> check;
        for (int i = 0; i < strs.size(); i++)
        {
            int l = strs[i].length();
            if (m.find(strs[i]) == m.end()) 
            {
                m[strs[i]] = 1;
            }
            else m[strs[i]]++;
            v.push_back(make_pair(l, strs[i]));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i+1; j < v.size(); j++)
            {
                bool flag = isSubsequence(v[i].second, v[j].second);
                if (flag) 
                {
                    check[v[i].second] = true;
                    break;
                }
            }
        }
        int n = v.size();
        for (int i = n-1; i >= 0; i--)
        {
            int l = v[i].second.length();
            if (m[v[i].second] == 1 && check[v[i].second] == false)
                return l;
        }
        return -1;
    }
private: 
    bool isSubsequence(string s, string t) {
        int i, prev = -1, m = s.length(), n = t.length();
        for (i = 0; i < m; i++)
        {
            int temp = FindChar(t, prev, s[i], n);
            if (temp > prev)
                prev = temp;
            else
                return false;
        }
        return true;
    }
    int FindChar(string t, int prev, char c, int n)
    {
        int ans;
        for (int j = prev+1; j < n; j++)
        {
            if (t[j] == c)
                return j;
        }
        return -1;
    }
};
