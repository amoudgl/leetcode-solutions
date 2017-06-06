// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n = 2*n;
        ans = G(n);
        return ans;
    }
    vector<string> G(int n)
    {
        vector<string> ans;        
        if (n == 0)
        {
            ans.push_back("");
            return ans;
        }
        else if (n < 0 || n % 2 != 0)
        {
            return ans;
        }
        else if (n == 2)
        {
            ans.push_back("()");
            return ans;
        }
        for (int i = 1; i <= n; i++)
        {
            vector<string> x = G(n-i);
            vector<string> y = G(i-2);
            if (x.size() != 0 && y.size() != 0)
            {
            for (int j = 0; j < x.size(); j++)
            {
                for (int k = 0; k < y.size(); k++)
                {
                    string s = "(" + x[j] + ")" + y[k];
                    if (s.length() == n)
                        ans.push_back(s);
                }
            }                
            }
            else if (x.size() != 0)
            {
                for (int j = 0; j < x.size(); j++)
                {
                    string s = "(" + x[j] + ")";
                    if (s.length() == n)
                        ans.push_back(s);    
                }                  
            }
            else if (y.size() != 0)
            {
                for (int k = 0; k < y.size(); k++)
                {
                    string s = "()" + y[k];
                    if (s.length() == n)
                        ans.push_back(s);
                }                
            }
        }
        return ans;
    }
};
