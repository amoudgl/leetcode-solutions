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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = f(nums, 0, n-1);
        return root;
    }
    TreeNode *f(vector<int> &nums, int i, int j)
    {
        if (i <= j)
        {
            int m = INT_MIN, ind;
            for (int k = i; k <= j; k++)
            {
                if (nums[k] > m)
                {
                    ind = k;
                    m = nums[k];
                }
            }   
            TreeNode *root = new TreeNode(m);
            root->left = f(nums, i, ind-1);
            root->right = f(nums, ind+1, j);
            return root;
        }
        return NULL;
    }
};
