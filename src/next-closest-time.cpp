// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    bool check(string time)
    {
        int hours = stoi(time.substr(0,2));
        int minutes = stoi(time.substr(3,2));
        if (minutes < 60 && hours < 24) return true;
        return false;
    }
    string nextClosestTime(string time) {
        int h1 = stoi(time.substr(0,1));
        int h2 = stoi(time.substr(1,1));
        int m1 = stoi(time.substr(3,1));
        int m2 = stoi(time.substr(4,1));
        vector<int> a;
        a.push_back(h1);
        a.push_back(h2);
        a.push_back(m1);
        a.push_back(m2);
        sort(a.begin(), a.end());
        for (int i = 0; i < 4; i++)
        {
            if (a[i] > m2)
            {
                string x = time;
                x[4] = a[i]+48;
                if (check(x)) return x;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (a[i] > m1)
            {
                string x = time;
                x[3] = a[i]+48;
                x[4] = a[0]+48;
                if (check(x)) return x;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (a[i] > h2)
            {
                string x = time;
                x[1] = a[i]+48;
                x[3] = a[0]+48;
                x[4] = a[0]+48;
                if (check(x)) return x;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (a[i] > h1)
            {
                string x = time;
                x[0] = a[i]+48;
                x[1] = a[0]+48;
                x[3] = a[0]+48;
                x[4] = a[0]+48;                
                if (check(x)) return x;
            }
        }
        time[0] = a[0]+48;
        time[1] = a[0]+48;
        time[3] = a[0]+48;
        time[4] = a[0]+48;
        return time;
    }
};
