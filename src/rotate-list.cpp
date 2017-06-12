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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr;
        ListNode *HEAD;
        ptr = head;
        HEAD = head;
        int l = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            l++;
        }
        if (l == 0) return NULL;
        ptr = head;
        k = k % l;
        Rotate(HEAD, ptr, k);
        return HEAD;
    }
    void Rotate(ListNode* &head, ListNode *ptr, int &k)
    {
        if (ptr == NULL)
            return;
        else if (ptr->next == NULL) ptr->next = head;
        else Rotate(head, ptr->next, k);
        k--;
        if (k == -1)
        {
            head = ptr->next;
            ptr->next = NULL;
        }
    }
};
