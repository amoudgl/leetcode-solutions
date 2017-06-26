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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        st.push(root);
        while (!st.empty())
        {
            auto p = st.top();
            if (p == NULL)
            {
                st.pop();
                continue;
            }
            int x = rightmostVal(p);
            if ((p->left == NULL && p->right == NULL) || (!ans.empty() && ans.back() == x))
            {
                ans.push_back(p->val);
                st.pop();
            }
            else if ((p->left != NULL && !ans.empty() && ans.back() == p->left->val) || p->left == NULL) st.push(p->right);
            else st.push(p->left);
        }
        return ans;
    }
private:
    int rightmostVal(TreeNode *p)
    {
        if (p->right != NULL) return p->right->val;
        else if (p->left != NULL) return p->left->val;
        return -1;
    }
};
