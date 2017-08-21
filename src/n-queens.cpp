// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int> > queens; 
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string s;
            for (int j = 0; j < n; j++)
                s += ".";
            v.push_back(s);
        }
        f(0, v, queens);
        return ans;
    }
    void f(int k, vector<string> v, vector<pair<int, int> > queens)
    {
        int N = v.size();
        if (k == N)
        {
            ans.push_back(v);
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
                v[k][i] = 'Q';
                queens.push_back(make_pair(k, i));
                f(k+1, v, queens);
                v[k][i] = '.';
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
    vector<vector<string> > ans;
};
