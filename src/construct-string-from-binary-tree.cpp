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
    string tree2str(TreeNode* t) {
        string ans;
        FindString(t, ans);
        return ans;
    }
    void FindString(TreeNode *root, string &ans)
    {
        if (root != NULL)
        {
            ans += to_string(root->val);
            if (!(root->left == NULL && root->right == NULL))
            {
                ans += "(";
                FindString(root->left, ans);
                ans += ")";
            }
            if (root->right != NULL)
            {
                ans += "(";
                FindString(root->right, ans);
                ans += ")";                
            }
        }
    }
};
