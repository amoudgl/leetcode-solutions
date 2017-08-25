// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<pair<char, int> > st;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (c == ')' && (!st.empty() && st.top().first == '('))
            {
                int l = 0;
                auto q = st.top();
                l += (i-q.second+1);
                st.pop();
                if (!st.empty())
                    l += (q.second-st.top().second-1);
                else 
                    l += (q.second);
                if (l > ans) ans = l;
            }
            else 
                st.push(make_pair(s[i], i));
        }
        return ans;
    }
};
