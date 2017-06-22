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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        int j = -1;
        queue <pair<TreeNode *, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.first == NULL) continue;
            if (j < p.second)
            {
                ans.push_back(p.first->val);
                j++;
            }
            else if (j == p.second && p.first->val > ans[j])
            {
                ans[j] = p.first->val;
            }
            q.push(make_pair(p.first->left, p.second+1));
            q.push(make_pair(p.first->right, p.second+1));
        }
        return ans;
    }
};
