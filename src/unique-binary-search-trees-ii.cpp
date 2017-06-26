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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return vector<TreeNode*> ();
        return Generate(1, n);
    }
    vector<TreeNode*> Generate(int m, int n)
    {
        if (m <= n)
        {
            vector<TreeNode*> ans;
            for (int i = m; i <= n; i++)
            {
                vector<TreeNode *> l = Generate(m, i-1);
                vector<TreeNode *> r = Generate(i+1, n);
                for (int j = 0; j < l.size(); j++)
                {
                    for (int k = 0; k < r.size(); k++)
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = l[j];
                        node->right = r[k];
                        ans.push_back(node);
                    }
                }
            }
            return ans;
        }
        vector<TreeNode*> ans;
        ans.push_back(NULL);
        return ans;
    }
};
