// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        queue<UndirectedGraphNode *> q;
        q.push(node);  
        unordered_map<int, UndirectedGraphNode *> m;
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (m.find(curr->label) == m.end())
                m[curr->label] = new UndirectedGraphNode(curr->label); 
            for (auto neighbour : curr->neighbors)
            {
                if (m.find(neighbour->label) == m.end())
                {
                    m[neighbour->label] = new UndirectedGraphNode(neighbour->label);
                    q.push(neighbour);
                }
                m[curr->label]->neighbors.push_back(m[neighbour->label]);
            }
        }
        return m[node->label]; 
    }
};
