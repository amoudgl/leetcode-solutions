// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL)
        {
            return vector<double> ();
        }
        queue<pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        map<int, pair<long long int, int> > m;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (m.find(p.second) == m.end())
            {
                m[p.second] = make_pair(p.first->val, 1);
            }
            else if (m.find(p.second) != m.end())
            {
                m[p.second].first += (long long int) p.first->val;
                m[p.second].second += 1;
            }
            if (p.first->left != NULL)
                q.push(make_pair(p.first->left, p.second+1));
            if (p.first->right != NULL)
                q.push(make_pair(p.first->right, p.second+1));
        }
        vector<double> v;
        for (auto p : m)
        {
            double av = (double) p.second.first / (double) p.second.second;
            v.push_back(av);
        }
        return v;
    }
};
