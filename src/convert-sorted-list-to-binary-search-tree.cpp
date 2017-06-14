// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<pair<ListNode *, bool>> a;
        ListNode *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            ListNode *temp;
            temp = ptr;
            a.push_back(make_pair(temp, false));
            ptr = ptr->next;
        }
        int m = 0, n = a.size() - 1;
        root = NULL;
        root = GetBST(a, 0, n);
        return root;
    }
    TreeNode* GetBST(vector<pair<ListNode *, bool>> &a, int m, int n)
    {
        if (m <= n)
        {
            int mid;
            if ((m%2 == 0 & n%2 == 1) || (m%2 == 1 && n%2 == 0))
                mid = m+(n-m+1)/2;
            else 
                mid = m+(n-m)/2;
            TreeNode *temp;
            temp = NULL;
            if (a[mid].second == false)
            {
                temp = new TreeNode(a[mid].first->val);
                a[mid].second = true;
                if (root == NULL) root = temp;
                temp->left = GetBST(a, m, mid-1);
                temp->right = GetBST(a, mid+1, n);                
            }
            return temp;
        }
        return NULL;
    }
private:
    TreeNode *root;
};
