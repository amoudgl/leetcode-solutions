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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return root;
        TreeNode *x = NULL;
        if (root->val >= L && root->val <= R)
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            x = root;
        }
        if (x == NULL)
            x = trimBST(root->left, L, R);
        if (x == NULL)
            x = trimBST(root->right, L, R);
        return x;
    }

};
