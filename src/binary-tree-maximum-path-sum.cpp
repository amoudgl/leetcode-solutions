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
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int x = MaxPathSum(root);
        return ans;
    }
    int MaxPathSum(TreeNode* root) {
        if (root == NULL) return INT_MIN;
        if (m.find(root) == m.end())
        {
            int z;
            int x = MaxPathSum(root->left);
            int y = MaxPathSum(root->right);
            int a = findMaxSum(root->left);
            int b = findMaxSum(root->right);
            int c = root->val;
            if (a == INT_MIN && b == INT_MIN)
                z = c;
            else if (a == INT_MIN && b != INT_MIN)
                z = max(b+c, c);
            else if (a != INT_MIN && b == INT_MIN)
                z = max(a+c, c);
            else z = max(a+b+c, max(c, max(a+c, b+c)));
            m[root] = max(x, max(y, z));
            ans = max(ans, m[root]);
        }
        return m[root];
    }
    int findMaxSum(TreeNode *root)
    {
        if (root == NULL) return INT_MIN;
        else 
        {
            if (pathsum.find(root) == pathsum.end())
            {
                int x = findMaxSum(root->left);
                int y = findMaxSum(root->right);
                if (x == INT_MIN && y == INT_MIN)
                    pathsum[root] = root->val;
                else pathsum[root] = max(root->val, root->val + max(x, y));
            }
            return pathsum[root];
        }
    }
private:
    int ans;
    unordered_map<TreeNode*, int> m;
    unordered_map<TreeNode*, int> pathsum;
};
