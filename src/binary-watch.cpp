// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        unordered_map<string, bool> m;
        vector<bool> hours(6, false);
        vector<bool> minutes(6, false);
        FindPossibleTimings(m, hours, minutes, num, 0, 0);
        vector<string> ans;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            string x = i->first;
            ans.push_back(x);
        }
        m.clear();
        return ans;
    }
    void FindPossibleTimings(unordered_map<string, bool> &mp,
                             vector<bool> hours, vector<bool> minutes,
                             int num, 
                             int m, 
                             int n)
    {
        if (num == 0)
        {
            pair<bool, string> check = Check(hours, minutes);
            if (check.first) mp[check.second] = true;
            return;
        }
        else if (n >= 6) return;
        hours[m] = false;
        minutes[n] = false;
        FindPossibleTimings(mp, hours, minutes, num, m+1, n+1);
        
        hours[m] = false;
        minutes[n] = true;
        FindPossibleTimings(mp, hours, minutes, num-1, m+1, n+1);
        
        hours[m] = true;
        minutes[n] = false;
        FindPossibleTimings(mp, hours, minutes, num-1, m+1, n+1);
        
        hours[m] = true;
        minutes[n] = true;
        FindPossibleTimings(mp, hours, minutes, num-2, m+1, n+1);
    }
    pair<bool, string> Check(vector<bool> hours, vector<bool> minutes)
    {
        int h = 0, m = 0, x = 1;
        for (int i = 0; i < hours.size(); i++)
        {
            if (hours[i] == true) h += x;
            x = x*2;
        }
        x = 1;
        for (int i = 0; i < minutes.size(); i++)
        {
            if (minutes[i] == true) m += x;
            x = x*2;
        }
        pair<bool, string> p;
        string ans;
        if (h > 11 || m > 59)
        {
            p.first = false;
            return p;
        }
        p.first = true;
        ans = to_string(h) + ":";
        if (to_string(m).length() == 1) ans += "0" + to_string(m);
        else ans += to_string(m);
        p.second = ans;
        return p;
    }
};
