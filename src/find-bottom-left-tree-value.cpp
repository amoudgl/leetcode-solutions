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
    int findBottomLeftValue(TreeNode* root) {
        int depth = 0, value = -1, maxdepth = -1;
        FindValue(root, depth, maxdepth, value);
        return value;
    }
    void FindValue(TreeNode *root, int depth, int &maxdepth, int &value)
    {
        if (root != NULL)
        {
            FindValue(root->left, depth+1, maxdepth, value);
            if (depth > maxdepth)
            {
                value = root->val;
                maxdepth = depth;
            }
            FindValue(root->right, depth+1, maxdepth, value);
        }
    }
};
