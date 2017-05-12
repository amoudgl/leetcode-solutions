// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> s;
        unordered_map<char, int> g;
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                if (g.find(guess[i]) == g.end())
                    g[guess[i]] = 1;
                else 
                    g[guess[i]]++;
                if (s.find(secret[i]) == s.end())
                    s[secret[i]] = 1;
                else 
                    s[secret[i]]++;
            }
        }
        for (auto it = g.begin(); it != g.end(); it++)
        {
            if (s.find(it->first) != s.end())
            {
                if (s[it->first] > g[it->first])
                    cows += g[it->first];
                else
                    cows += s[it->first];
            }
        }
        string ans;
        ans = to_string(bulls) + "A" + to_string(cows) + "B";
	s.clear();
	g.clear();
        return ans;
    }
};
