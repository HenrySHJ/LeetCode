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

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;

    while (cur) {
        ListNode* temp = cur;
        cur = cur->next;
        
        temp->next = prev;
        prev = temp;
    }

    return prev;
}