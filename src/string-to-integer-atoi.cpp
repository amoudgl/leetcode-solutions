// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int myAtoi(string str) {
        str = strip(str);
        if (str.length() == 0 || str == "+" || str == "-") return 0;
        return getint(str);
    }
private:
    string strip(string s)
    {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && ans.length() == 0) continue;
            else if (s[i] >= '0' && s[i] <= '9') ans += s[i];
            else if ((s[i] == '+' || s[i] == '-') && ans.length() == 0) ans += s[i];
            else break;
        }
        return ans;
    }
    int getint(string s)
    {
        int num = 0;
        bool overflow = false;
        bool flag = (s[0] == '-') ? true : false;
        reverse(s.begin(), s.end());
        int ten = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (overflow) return (flag) ? INT_MIN : INT_MAX;
                
                if ((s[i]-48) > INT_MAX/ten) return (flag) ? INT_MIN : INT_MAX;
                int x = (ten * (s[i]-48));
                
                if (num > INT_MAX-x) return (flag) ? INT_MIN : INT_MAX;
                else num += x;
                
                if (ten > INT_MAX/10) overflow = true;
                else ten = ten*10;
            }
        }
        return (flag) ? -num : num;
    }
};
