// Author: Abhinav Moudgil [ https://leetcode.com/amoudgl/ ]
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *ptr, *prev;
        RandomListNode *HEAD;
        HEAD = NULL;
        ptr = head;
        unordered_map<RandomListNode*, RandomListNode*> m;
        while (ptr != NULL)
        {
            RandomListNode *p;
            int x = ptr->label;
            p = new RandomListNode(x);
            if (ptr == head) HEAD = p;
            else prev->next = p;
            m[ptr] = p;
            prev = p;
            ptr = ptr->next;
        }
        ptr = head;
        RandomListNode *p1, *p2, *ptr2, *r;
        r = HEAD;
        while (ptr != NULL)
        {
            p1 = ptr->random;
            if (p1 == NULL) r->random = NULL;
            else r->random = m[p1];
            ptr = ptr->next;
            r = r->next;
        }
        return HEAD;
    }
};
