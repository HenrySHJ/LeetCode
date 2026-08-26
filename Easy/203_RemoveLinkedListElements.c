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

ListNode* removeElements(ListNode* head, int val) {
    ListNode* cur = head;
    ListNode* prev = NULL;

    while (cur) {
        ListNode* temp = cur;
                
        if (cur->val == val) {
            if (prev) 
                prev->next = cur->next;
            else
                head = cur->next;
            cur = cur->next;
            free(temp);
        }
        else {
            prev = cur;
            cur = cur->next;
        }
        
    }

    return head;
}