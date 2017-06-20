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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int sum = FindSum(root, m);
        int Max = 0;
        for (auto p : m) Max = max(p.second, Max);
        vector<int> ans;
        for (auto p : m)
        {
            if (p.second == Max)
                ans.push_back(p.first);
        }
        return ans;
    }
    int FindSum(TreeNode *root, unordered_map<int, int> &m)
    {
        if (root == NULL) return 0;
        int sum = root->val + FindSum(root->left, m) + FindSum(root->right, m);
        if (m.find(sum) == m.end()) m[sum] = 1;
        else m[sum]++;
        return sum;
    }
        
};
