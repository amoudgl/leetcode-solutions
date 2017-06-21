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
    int findTilt(TreeNode* root) {
        int tilt = 0;
        int sum = FindSum(root, tilt);
        return tilt;
    }
    int FindSum(TreeNode *root, int &tilt)
    {
        if (root == NULL) return 0;
        int x = FindSum(root->left, tilt);
        int y = FindSum(root->right, tilt);
        tilt += abs(x-y);
        return root->val + x + y;
    }
};
