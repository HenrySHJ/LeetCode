# include <stdio.h>
# include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* p1 = headA;
    ListNode* p2 = headB;

    // a + b + c = b + a + c
    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;
}
