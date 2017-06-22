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
        int curr = 0;
        sum = 0;
        GetSum(root);
        ConvertBST(root, curr);
        return root;
    }
    void GetSum(TreeNode *root)
    {
        if (root != NULL)
        {
            GetSum(root->left);
            sum += root->val;
            GetSum(root->right);
        }
    }
    void ConvertBST(TreeNode *root, int &curr)
    {
        if (root != NULL)
        {
            ConvertBST(root->left, curr);
            int temp = root->val;
            root->val = sum - curr;
            curr += temp;
            ConvertBST(root->right, curr);
        }
    }
private:
    int sum;
};
