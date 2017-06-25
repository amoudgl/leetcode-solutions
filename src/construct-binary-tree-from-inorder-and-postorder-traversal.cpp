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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = 0, j = inorder.size()-1;
        root = NULL;
        k = inorder.size();
        root = Build(postorder, inorder, i, j);
        return root;        
    }
    TreeNode* Build(vector<int>& postorder, vector<int>& inorder, int m, int n)
    {
        if (m <= n)
        {
            k--;
            int value = postorder[k];
            int i;
            for (i = m; i <= n; i++)
            {
                if (value == inorder[i])
                    break;
            }
            TreeNode *node = new TreeNode(value);
            node->right = Build(postorder, inorder, i+1, n);
            node->left = Build(postorder, inorder, m, i-1);
            return node;
        }
        return NULL;
    }
private:
    TreeNode* root;
    int k;
};
