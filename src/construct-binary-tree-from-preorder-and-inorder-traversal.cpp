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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0, j = inorder.size()-1;
        root = NULL;
        k = -1;
        root = Build(preorder, inorder, i, j);
        return root;
    }
    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int m, int n)
    {
        if (m <= n)
        {
            k++;
            int value = preorder[k];
            int i;
            for (i = m; i <= n; i++)
            {
                if (value == inorder[i])
                    break;
            }
            TreeNode *node = new TreeNode(value);
            node->left = Build(preorder, inorder, m, i-1);
            node->right = Build(preorder, inorder, i+1, n);
            return node;
        }
        return NULL;
    }
private:
    TreeNode* root;
    int k;
};
