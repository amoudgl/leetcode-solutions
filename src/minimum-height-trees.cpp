// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int> > graph(n);
        for (auto edge : edges)
        {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        if (n == 1)
        {
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }
        vector<int> curr, next;
        for (int i = 0; i < n; i++)
            if (graph[i].size() == 1) curr.push_back(i);
        while (true)
        {
            for (auto node : curr)
            {
                for (auto neighbour : graph[node])
                {
                    graph[neighbour].erase(node);
                    if (graph[neighbour].size() == 1) next.push_back(neighbour);
                }
            }
            if (next.empty()) return curr;
            curr = next;
            next = vector<int> ();
        }
    }
};
