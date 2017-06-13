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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ptr, *prev;
        ptr = head;
        prev = NULL;
        while (ptr != NULL)
        {
            ListNode *nxt;
            if (ptr->next == NULL)
            {
                if (prev != NULL)
                    prev->next = ptr;
                break;
            }
            else 
                nxt = ptr->next->next;
            ListNode *p1 = ptr;
            ListNode *p2 = ptr->next;
            p2->next = p1;
            if (p1 == head)
                head = p2;
            if (prev != NULL)
                prev->next = p2;
            prev = p1;
            prev->next = NULL;
            ptr = nxt;
        }
        return head;
    }
};
