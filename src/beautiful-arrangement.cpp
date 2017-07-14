// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int countArrangement(int N) {
        ans = 0;
        unordered_set<int> s;
        count(1, N, s);
        return ans;
    }
    void count(int i, int N, unordered_set<int> s)
    {
        if (i > N)
        {
            ans++;
            return;
        }
        else if (s.size() == N) return;
        for (int j = 1; j <= N; j++)
        {
            if (s.find(j) == s.end() && (j % i == 0 || i % j == 0))
            {
                s.insert(j);       
                count(i+1, N, s);
                s.erase(j);
            }
        }
    }
private:
    int ans;
};
