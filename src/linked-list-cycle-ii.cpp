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
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr1, *ptr2; 
        if (head == NULL) return NULL;
        ptr1 = head->next;
        if (head->next != NULL)
            ptr2 = head->next->next;
        else    
            return NULL;
        while (ptr1 != NULL && ptr2 != NULL && ptr1 != ptr2)
        {
            if (ptr1 != NULL)
                ptr1 = ptr1->next;
            else
                return NULL;
            if (ptr2->next != NULL)
                ptr2 = ptr2->next->next;
            else 
                return NULL;
        }
        if (ptr1 == NULL || ptr2 == NULL) return NULL;
        ptr1 = head;
        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
