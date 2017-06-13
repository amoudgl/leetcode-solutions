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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 0;
        ListNode *ptr = head;
        ListNode *p1, *p2, *p3, *p4, *prev, *nxt;
        p1 = p2 = NULL;
        p3 = p4 = NULL;
        prev = NULL;
        while (ptr != NULL)
        {
            i++;
            nxt = ptr->next;
            if (i > m && i <= n)
            {
                ptr->next = prev;
            }
            if (i == m-1)
                p1 = ptr;
            else if (i == m)
                p2 = ptr;
            if (i == n)
                p3 = ptr;
            else if (i == n+1)
                p4 = ptr;
            prev = ptr;
            ptr = nxt;
        }
        if (p1 != NULL)
            p1->next = p3;
        if (p2 != NULL)
            p2->next = p4;
        if (head != NULL && head == p2)
            head = p3;
        return head;
    }
};
