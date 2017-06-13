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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr, *ptr1, *ptr2, *h;
        ptr = head;
        ptr1 = NULL;
        ptr2 = NULL;
        h = NULL;
        while (ptr != NULL)
        {
            if (ptr->val < x)
            {
                if (ptr1 != NULL)
                    ptr1->next = ptr;
                else
                    head = ptr;
                ptr1 = ptr;
            }
            else if (ptr->val >= x)
            {
                if (ptr2 != NULL)
                    ptr2->next = ptr;
                else 
                    h = ptr;
                ptr2 = ptr;
            }
            ptr = ptr->next;
        }
        if (h != NULL && ptr1 != NULL)
            ptr1->next = h;
        if (ptr2 != NULL)
            ptr2->next = NULL;
        return head;
    }
};
