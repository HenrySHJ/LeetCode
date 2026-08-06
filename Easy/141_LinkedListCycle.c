# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

bool hasCycle(ListNode *head) {
    ListNode* cur = head;
    while (cur) {
        if (cur->val == INT_MAX)
            return true;

        cur->val = INT_MAX;
        cur = cur->next;
    }
    return false;
}