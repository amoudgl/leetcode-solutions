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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, prev = -1;
        f(root, prev, ans);
        return ans;
    }
    void f(TreeNode *root, int& prev, int& ans)
    {
        if (root)
        {
            f(root->left, prev, ans);
            if (prev != -1) ans = min(abs(prev - root->val), ans);
            prev = root->val;
            f(root->right, prev, ans);
        }
    }
};
