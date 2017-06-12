// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> st;
        string digit;
        NestedInteger ans;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9' || s[i] == '-')
            {
                digit += s[i];
            }
            else if (s[i] == '[')
            {
                digit.clear();
                NestedInteger x; 
                st.push(x);
            }
            else if (s[i] == ',')
            {
                if (digit.length() > 0)
                {
                    int num = stoi(digit);
                    digit.clear();
                    NestedInteger x(num);
                    auto p = st.top();
                    p.add(x);
                    st.pop();
                    st.push(p);
                }
            }
            else if (s[i] == ']')
            {
                auto p = st.top();
                if (digit.length() > 0)
                    p.add(stoi(digit));
                st.pop();
                if (!st.empty())
                {
                    auto p2 = st.top();
                    p2.add(p);
                    st.pop();
                    st.push(p2);
                }
                else
                    st.push(p);
                digit.clear();
            }
        }
        if (!st.empty())
            ans = st.top();
        else if (digit.length() > 0)
            ans.setInteger(stoi(digit));
        return ans;
    }
};
