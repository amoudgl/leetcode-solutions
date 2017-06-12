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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p1;
        ListNode *p2;
        p1 = NULL;
        p2 = NULL;        
        OddEvenList(head, p1, p2, 0);
        head = p1;
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        p1->next = p2;
        return head;
    }
    void OddEvenList(ListNode* head, ListNode* &p1, ListNode* &p2, int l)
    {
        if (head == NULL)
            return;
        OddEvenList(head->next, p1, p2, l+1);  
        if (p1 != NULL && p2 != NULL && l%2 == 0)
        {
            head->next = p1;
            p1 = head;
        }
        else if (p1 != NULL && p2 != NULL && l%2 == 1)
        {
            head->next = p2;
            p2 = head;
        }        
        else if (head->next == NULL)
        {
            if (l%2 == 0)
                p1 = head;
            else 
                p2 = head;
        }
        else if (head->next->next == NULL)
        {
            if (l%2 == 0)
                p1 = head;
            else 
                p2 = head;
            head->next = NULL;
        }
    }
};
