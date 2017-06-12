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
    bool hasCycle(ListNode *head) {
        ListNode *ptr1, *ptr2;
        if (head == NULL || head->next == NULL) return false;        
        ptr1 = head->next;
        ptr2 = head->next->next;
        while (ptr1 != ptr2)
        {
            if (ptr1 == NULL || ptr2 == NULL)
                return false;            
            ptr1 = ptr1->next;
            if (ptr2->next != NULL)
                ptr2 = ptr2->next->next;
            else return false;
        }
        return true;
    }
};
