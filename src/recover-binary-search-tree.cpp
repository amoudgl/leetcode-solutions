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
    void recoverTree(TreeNode* root) {
        p1 = p2 = NULL;
        p3 = NULL;
        TreeNode *prev;
        prev = NULL;
        Recover(root, prev);
        if (p1 != NULL && p2 != NULL)
        {
            int temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;
        }
        else if (p1 != NULL && p2 == NULL)
        {
            if (p3 != NULL)
            {
                int temp = p1->val;
                p1->val = p3->val;
                p3->val = temp;
            }
        }
    }
    void Recover(TreeNode* root, TreeNode* &prev)
    {
        if (root != NULL)
        {
            Recover(root->left, prev);
            if (prev == NULL) prev = root;
            else if (p1 == NULL && prev->val > root->val) p1 = prev;
            else if (p1 != NULL && prev->val > root->val) p2 = root;
            if (p1 != NULL && prev == p1) p3 = root;
            prev = root;
            Recover(root->right, prev);
        }
    }
private: 
    TreeNode *p1, *p2, *p3;
};
