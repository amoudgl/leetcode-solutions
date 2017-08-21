// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int totalNQueens(int n) {
        ans = 0;
        vector<pair<int, int> > queens; 
        f(0, n, queens);
        return ans;
    }
    void f(int k, int N, vector<pair<int, int> > queens)
    {
        if (k == N)
        {
            ans++;
            return;
        }
        for (int i = 0; i < N; i++)
        {
            int flag = 0;
            for (auto x : queens)
            {
                if (check(x, k, i))
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                queens.push_back(make_pair(k, i));
                f(k+1, N, queens);
                queens.pop_back();
            }
        }
    }
    bool check(pair<int, int> p, int x2, int y2)
    {
        int x1 = p.first;
        int y1 = p.second;
        if (y1 == y2 || abs(x1-x2) == abs(y1-y2)) return true;
        else return false;
    }
private:
    int ans;  
};
