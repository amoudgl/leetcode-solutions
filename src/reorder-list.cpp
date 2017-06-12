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
    void reorderList(ListNode* head) {
        ListNode* ptr1;
        ListNode* ptr2;
        ptr1 = head;
        ptr2 = head;
        int flag = 0;
        ReorderList(ptr1, ptr2, flag);
    }
    void ReorderList(ListNode* &ptr1, ListNode* ptr2, int &flag)
    {
        if (ptr2 == NULL)
        {
            return;
        }
        ReorderList(ptr1, ptr2->next, flag);
        if (!flag && ptr1 != NULL && ptr1->next != ptr2 && ptr1 != ptr2)
        {
            ListNode *ptr3;
            ptr3 = ptr1->next;
            ptr1->next = ptr2;
            ptr2->next = ptr3;
            ptr1 = ptr3;
        }
        else if (!flag && (ptr1->next == ptr2 || ptr1 == ptr2))
        {
            ptr2->next = NULL;
            flag = 1;
        }
    }
};
