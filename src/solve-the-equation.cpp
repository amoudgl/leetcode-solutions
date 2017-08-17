// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string solveEquation(string equation) {
        string lhs = equation.substr(0, equation.find("="));
        string rhs = equation.substr(equation.find("=")+1);
        auto l = f(lhs);
        auto r = f(rhs);
        if (l.second == r.second && l.first != r.first) return "No solution";
        else if (l.second == r.second && l.first == r.first) return "Infinite solutions";
        int ans = (r.first-l.first)/(l.second-r.second);
        return "x="+to_string(ans);
    }
    pair<int, int> f(string lhs)
    {
        int nx_lhs = 0, l_sum = 0, flag = 0;
        string num = "";
        for (char c : lhs)
        {
            if (c >= '0' && c <= '9') num += c;
            else if (c == '+' || c == '-')
            {
                if (flag && num.length() > 0) l_sum -= stoi(num);
                else if (!flag && num.length() > 0) l_sum += stoi(num);
                if (c == '-') flag = 1;
                else if (c == '+') flag = 0;
                num = "";
            }
            else if (c == 'x')
            {
                if (flag && num.length() > 0) nx_lhs -= stoi(num);
                else if (!flag && num.length() > 0) nx_lhs += stoi(num);
                else if (flag && num.empty()) nx_lhs -= 1;
                else if (!flag && num.empty()) nx_lhs += 1;
                num = "";
                flag = 0;
            }
        }
        if (num.length() > 0)
        {
            if (flag) l_sum -= stoi(num);
            else l_sum += stoi(num);
            num = "";
        }
        return make_pair(l_sum, nx_lhs);
    }
};
