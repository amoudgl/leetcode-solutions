// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, n = lists.size(), min = INT_MAX, minInd, flag = 0; 
        ListNode *head, *prev, *ptr; 
        if (n == 0) return NULL;
        for (i = 0; i < n; i++)
        {
            if (lists[i] != NULL && lists[i]->val <= min)
            {
                flag = 1;
                min = lists[i]->val;
                head = lists[i];
                minInd = i;
            }
        }
        if (!flag) return NULL;
        prev = head;
        int headInd = minInd;
        lists[minInd] = lists[minInd]->next;
        flag = 1;
        while (flag)
        {
            flag = 0;
            min = INT_MAX;
            for (i = 0; i < n; i++)
            {
                if (lists[i] != NULL && lists[i]->val <= min)
                {
                    flag = 1;
                    min = lists[i]->val;
                    minInd = i;
                }
            }
            if (!flag) break;
            prev->next = lists[minInd];
            prev = lists[minInd];
            lists[minInd] = lists[minInd]->next;
        }
        return head;
    }
};
