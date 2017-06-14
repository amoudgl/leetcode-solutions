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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ptr, *p1, *p2;
        ptr = head;
        p2 = NULL;
        while (ptr != NULL)
        {
            p1 = ptr;
            ListNode *prev;
            int m = INT_MAX;
            ListNode *minptr;
            ListNode *minprev;
            prev = NULL;        
            minprev = NULL;
            while (p1 != NULL)
            {
                if (p1->val <= m)
                {
                    m = p1->val;
                    minptr = p1;
                    minprev = prev;
                }
                prev = p1;
                p1 = p1->next;
            }
            if (minprev != NULL)
                minprev->next = minptr->next;
                
            if (p2 == NULL) head = minptr;
            else p2->next = minptr;
            
            if (minptr != ptr)
                minptr->next = ptr; 
            p2 = minptr; 
            ptr = minptr->next;
        }
        return head;
    }
};
