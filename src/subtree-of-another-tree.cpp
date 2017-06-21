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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool a, b;
        if (s == NULL && t == NULL) return true;
        else if (s == NULL) return false;
        else if (s->val != t->val)
        {
            a = isSubtree(s->left, t);
            b = isSubtree(s->right, t);
        }
        else if (s->val == t->val)
        {
            a = CheckDiff(s, t);
            if (a == false)
            {
                a = isSubtree(s->left, t);
                b = isSubtree(s->right, t);
            }
            else return a;
        }
        return a | b;
    }
    bool CheckDiff(TreeNode* s, TreeNode* t)
    {
        if (s == NULL && t == NULL) return true;
        else if (s == NULL || t == NULL) return false;
        else if (s->val != t->val) return false;
        return (CheckDiff(s->left, t->left) & CheckDiff(s->right, t->right));
    }
};
