// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<char, int> m;
        unordered_set<string> st;
        int count = 0, l = s.length();
        sort(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++)
        {
            st.insert(words[i]);
            for (int j = 0; j < words[i].length(); j++)
            {
                if (m.find(words[i][j]) == m.end()) m[words[i][j]] = 1;
                else m[words[i][j]]++;
                count++;
            }
        }
        unordered_map<char, int> m_temp;
        vector<int> ans;
        for (int i = 0; i < (l-count+1); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < count; j++)
                {
                    if (m_temp.find(s[j]) == m_temp.end())
                        m_temp[s[j]] = 1;
                    else m_temp[s[j]]++;
                }
            }
            else
            {
                m_temp[s[i-1]]--;
                if (m_temp[s[i-1]] == 0)
                    m_temp.erase(s[i-1]);
                if (m_temp.find(s[i+count-1]) == m_temp.end())
                    m_temp[s[i+count-1]] = 1;
                else 
                    m_temp[s[i+count-1]]++;
            }
            if (m_temp == m && check(s.substr(i, count), st, words))
                ans.push_back(i);
        }
        return ans;
    }
    bool check(string x, unordered_set<string> st, vector<string> &words)
    {
        string word;
        vector<string> s;
        for (char c : x)
        {
            word += c;
            if (st.find(word) != st.end())
            {
                s.push_back(word);
                word = "";
            }
        }
        sort(s.begin(), s.end());
        if (s == words) return true;
        return false;
    }
};
