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

ListNode *detectCycle(ListNode *head) {
    ListNode* p1 = head;
    ListNode* p2 = head;

    do {   
        // Slow Pointer
        if (p1) p1 = p1->next;

        // Fast Pointer
        if (p2) p2 = p2->next;
        if (p2) p2 = p2->next;

    } while (p1 != p2 && p2 != NULL);

    if (p2 == NULL)
        return NULL;

    p1 = head;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}