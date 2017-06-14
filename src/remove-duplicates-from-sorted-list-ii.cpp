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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev, *ptr, *p;
        int count = 1;
        p = NULL;
        prev = head;
        if (head != NULL) ptr = head->next;
        else return head;
        head = NULL;
        while (ptr != NULL)
        {
            if (ptr->val == prev->val) count++;
            else if (ptr->val != prev->val)
            {
                if (count == 1)
                {
                    if (p != NULL) p->next = prev;
                    else head = prev;
                    p = prev;
                    
                }
                count = 1;
            }
            prev = prev->next;
            ptr = ptr->next;
        }
        if (count == 1)
        {
            if (p != NULL) p->next = prev;
            else head = prev;
            p = prev;
            
        }
        if (p != NULL) p->next = NULL;
        return head;
    }
};
