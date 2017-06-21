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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int prev, count = 0;
        mode = 0;
        FindModes(root, ans, prev, count);
        if (root != NULL)
        {
            if (count > mode)
            {
                ans.clear();
                mode = count;
                ans.push_back(prev);
            }
            else if (count == mode)
            {
                ans.push_back(prev);
            }
        }
        return ans;
    }
    void FindModes(TreeNode *root, vector<int> &ans, int &prev, int &count)
    {
        if (root != NULL)
        {
            FindModes(root->left, ans, prev, count);
            if (count != 0 && prev != root->val)
            {
                if (count > mode)
                {
                    ans.clear();
                    mode = count;
                    ans.push_back(prev);
                }
                else if (count == mode)
                {
                    ans.push_back(prev);
                }
                count = 0;
            }
            prev = root->val;
            count++;
            FindModes(root->right, ans, prev, count);
        }
    }
private:
    int mode;
};
