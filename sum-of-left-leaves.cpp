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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findSum(root, sum);
        return sum; 
    }
    void findSum(TreeNode* root, int& sum)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
        {
            if (root->left->left == NULL && root->left->right == NULL)
                sum += root->left->val;
            findSum(root->left, sum);
        }
        if (root->right != NULL)
            findSum(root->right, sum);
    }
};
