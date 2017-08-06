// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
struct C
{
    bool operator()(const pair<char, int> &a, const pair<char, int> &b) const
    {
        if (a.second == b.second)
            return a.first < b.first;
        else 
            return a.second < b.second;
    }
};

class Solution {
public: 
    int characterReplacement(string s, int k) {
        int i = 0, n = s.length(), j = 0, ans = 0;
        while (i < n)
        {
            int l = i-j+1;
            increaseKey(s[i]);
            int x = findMax();
            while (l-x > k && j < i)
            {
                decreaseKey(s[j]);
                j++;
                l--;
                x = findMax();
            }
            ans = max(ans, l);
            i++;
        }
        return ans;
    } 
private:
    unordered_map<char, int> m;
    set<pair<char, int>, C> st;
    int findMax()
    {
        auto it = st.rbegin();
        return it->second;
    }
    void decreaseKey(char c)
    {
        st.erase(make_pair(c, m[c]));
        m[c] = m[c]-1;
        st.insert(make_pair(c, m[c]));
    }
    void increaseKey(char c)
    {
        if (m.find(c) == m.end())
        {
            m[c] = 1;
            st.insert(make_pair(c, m[c]));  
        }
        else 
        {
            st.erase(make_pair(c, m[c]));
            m[c]++; 
            st.insert(make_pair(c, m[c])); 
        }    
    }
};
