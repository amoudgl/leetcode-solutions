// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ] 
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for (auto s : ops)
        {
            if (s == "+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if (s == "D")
            {
                int x = st.top();
                st.push(2*x);
            }
            else if (s == "C")
            {
                st.pop();
            }
            else 
            {
                int x = stoi(s);
                st.push(x);
            }
        }
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
