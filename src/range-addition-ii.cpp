// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int m1 = m, m2 = n;
        for (int i = 0; i < ops.size(); i++)
        {
            if (ops[i][0] < m1) m1 = min(ops[i][0], m);
            if (ops[i][1] < m2) m2 = min(ops[i][1], n);
        }
        return m1*m2;
    }
};
