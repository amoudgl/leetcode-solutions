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
    int rob(TreeNode* root) {
        Rob(root);
        return dp[root];
    }
    void Rob(TreeNode *root)
    {
        if (root != NULL)
        {
            Rob(root->left);
            Rob(root->right);
            if (root->left == NULL && root->right == NULL)
            {
                dp[root] = root->val;
                return;
            }
            int x1 = root->val;
            int y1 = (root->left == NULL) ? y1 = 0 : y1 = dp[root->left];
            int y2 = (root->right == NULL) ? y2 = 0 : y2 = dp[root->right];
            int x2 = (root->left == NULL || (root->left != NULL && root->left->left == NULL)) ? 
                x2 = 0 : x2 = dp[root->left->left];
            int x3 = (root->left == NULL || (root->left != NULL && root->left->right == NULL)) ?
                x3 = 0 : x3 = dp[root->left->right];
            int x4 = (root->right == NULL || (root->right != NULL && root->right->left == NULL)) ?
                x4 = 0 : x4 = dp[root->right->left];
            int x5 = (root->right == NULL || (root->right != NULL && root->right->right == NULL)) ?
                x5 = 0 : x5 = dp[root->right->right];
            dp[root] = max(y1+y2, x1+x2+x3+x4+x5);
        }
    }
private:
    unordered_map<TreeNode*, int> dp;
};
