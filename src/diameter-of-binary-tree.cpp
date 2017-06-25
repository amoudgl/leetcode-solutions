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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int x = diameterOfBinaryTree(root->left);
        int y = diameterOfBinaryTree(root->right);
        int z = findMaxDepth(root->left) + findMaxDepth(root->right);
        return max(x, max(y, z));
    }
    int findMaxDepth(TreeNode *root)
    {
        if (root == NULL) return 0;
        else return 1 + max(findMaxDepth(root->right), findMaxDepth(root->left));
    }
};
