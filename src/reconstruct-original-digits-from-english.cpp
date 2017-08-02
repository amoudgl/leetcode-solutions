// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> m;
        for (auto c : s)
        {
            if (m.find(c) == m.end()) m[c] = 1;
            else m[c]++;
        }
        string ans;
        int n = m['z'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "0";
            m['z'] -= n; m['e'] -= n; m['r'] -= n; m['o'] -= n;
        }
        // twos
        n = m['w'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "2";
            m['t'] -= n; m['w'] -= n; m['o'] -= n;
        }
        n = m['u'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "4";
            m['f'] -= n; m['o'] -= n; m['u'] -= n; m['r'] -= n;
        }
        n = m['x'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "6";
            m['s'] -= n; m['i'] -= n; m['x'] -= n;
        }
        n = m['g'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "8";
            m['e'] -= n; m['i'] -= n; m['g'] -= n; m['h'] -= n; m['t'] -= n;
        }        
        n = m['t'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "3";
            m['t'] -= n; m['h'] -= n; m['r'] -= n; m['e'] -= 2*n;
        }        
        n = m['f'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "5";
            m['f'] -= n; m['i'] -= n; m['v'] -= n; m['e'] -= n;
        } 
        n = m['s'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "7";
            m['s'] -= n; m['v'] -= n; m['n'] -= n; m['e'] -= 2*n;
        }
        n = m['i'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "9";
            m['n'] -= 2*n; m['i'] -= n; m['e'] -= n;
        }
        n = m['o'];
        if (n > 0)
        {
            for (int i = 0; i < n; i++) ans += "1";
            m['n'] -= n; m['o'] -= n; m['e'] -= n;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
