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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<pair<TreeNode*, int> > q;
        if (d == 1)
        {
            TreeNode *newroot = new TreeNode (v);
            newroot->left = root;
            return newroot;
        }
        else q.push(make_pair(root, 1));
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.second == d-1 && p.first != NULL)
            {
                TreeNode *l = p.first->left;
                TreeNode *r = p.first->right;
                TreeNode *newl = new TreeNode (v);
                TreeNode *newr = new TreeNode (v);
                newl->left = l;
                newr->right = r;
                p.first->left = newl;
                p.first->right = newr;
            }
            else if (p.second < d-1 && p.first != NULL)
            {
                TreeNode *p1 = p.first->left;
                TreeNode *p2 = p.first->right;
                q.push(make_pair(p1, p.second+1));
                q.push(make_pair(p2, p.second+1));
            }
        }
        return root;
    }
};
