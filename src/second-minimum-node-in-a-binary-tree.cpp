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
    int findSecondMinimumValue(TreeNode* root) {
        if ((root == NULL) || (root->left == NULL))
            return -1;
        else
        {
            int x1 = root->val, t1, t2;
            int x2 = root->left->val;
            int x3 = root->right->val;
            if (x1 == x2) x2 = findSecondMinimumValue(root->left);
            if (x1 == x3) x3 = findSecondMinimumValue(root->right);
            if (x2 > 0 && x3 > 0) return min(x2, x3);
            else if (x2 > 0) return x2;
            else if (x3 > 0) return x3;
            return -1;
        }
    }
};
