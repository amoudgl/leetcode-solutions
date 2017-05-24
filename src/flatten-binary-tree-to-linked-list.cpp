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
    void flatten(TreeNode* root) {
        if (root != NULL)
        {
            flatten(root->left);
            if (root->left != NULL)
            {
                TreeNode *ptr = root->left;
                while (ptr->right != NULL)
                    ptr = ptr->right;
                ptr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            flatten(root->right);
        }
    }
};
