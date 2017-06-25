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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root != NULL)
        {
            if (root == p) return p;
            if (root == q) return q;
            TreeNode *x, *y;
            x = lowestCommonAncestor(root->left, p, q);
            y = lowestCommonAncestor(root->right, p, q);
            if (x != NULL && y != NULL) return root;
            else if (x != NULL) return x;
            else if (y != NULL) return y;
            return NULL;
        }
        return NULL;
    }
};
