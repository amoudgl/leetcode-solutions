class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m[s[i]] = 1;
            }
            else
                m[s[i]]++;
        }
        vector<pair<int, char> > v;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v.push_back(make_pair(it->second, it->first));
        }
        sort(v.begin(), v.end());
        string ans;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < v[i].first; j++)
                ans += v[i].second;
        }
        return ans;
    }
};
