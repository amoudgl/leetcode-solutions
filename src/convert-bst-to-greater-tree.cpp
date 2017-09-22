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
    TreeNode* convertBST(TreeNode* root) {
        int sum = CalcSum(root), prev = 0; 
        f(root, prev, sum);
        return root;
    }
    int CalcSum(TreeNode *root)
    {
        if (root)
        {
            return root->val + CalcSum(root->left) + CalcSum(root->right);
        }
        else return 0;
    }
    void f(TreeNode *root, int &prev, int sum)
    {
        if (root)
        {
            f(root->left, prev, sum);
            int x = prev;
            prev += root->val;
            root->val = sum - x;
            f(root->right, prev, sum);
        }
    }
};
