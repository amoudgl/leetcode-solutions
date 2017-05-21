// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> m;
        m['q'] = 1;
        m['w'] = 1;
        m['e'] = 1;
        m['r'] = 1;
        m['t'] = 1;
        m['y'] = 1;
        m['u'] = 1;
        m['i'] = 1;
        m['o'] = 1;
        m['p'] = 1;
        m['a'] = 2;
        m['s'] = 2;
        m['d'] = 2;
        m['f'] = 2;
        m['g'] = 2;
        m['h'] = 2;
        m['j'] = 2;
        m['k'] = 2;
        m['l'] = 2;
        m['z'] = 3;
        m['x'] = 3;
        m['c'] = 3;
        m['v'] = 3;
        m['b'] = 3;
        m['n'] = 3;
        m['m'] = 3;
        int i, j, n = words.size();
        vector<string> ans;
        for (i = 0; i < n; i++)
        {
            int temp = m[words[i][0]];
            if (words[i][0] >= 65 && words[i][0] <= 90)
                temp = m[words[i][0]+32];
            bool check = true;
            for (j = 1; j < words[i].length(); j++)
            {
                int t = m[words[i][j]];
                if (words[i][j] >= 65 && words[i][j] <= 90)
                    t = m[words[i][j]+32];
                if (temp != t)
                {
                    check = false;
                    break;
                }
            }
            if (check == true)
                ans.push_back(words[i]);
        }
        return ans;
    }        
};
