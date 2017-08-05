// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class DSU {
    public:
        vector<int> parent, sizeOfSet;
        DSU(int n) {
            parent = vector<int> (n);
            sizeOfSet = vector<int> (n, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }
        void join(int i, int j) {
            i = find(i);
            j = find(j);
            if (sizeOfSet[i] < sizeOfSet[j]) {
                swap(i, j);
            }
            parent[j] = i;
            sizeOfSet[i] += sizeOfSet[j];
            sizeOfSet[j] = 0;
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return 0;
        DSU dsu(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (dsu.find(i) != dsu.find(j) && M[i][j] == 1) dsu.join(i, j);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.sizeOfSet[i] > 0) count++;
        }
        return count;
    }
};

