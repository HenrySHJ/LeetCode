# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    
    while (cur != NULL) {
        while (cur->next && (cur->val == cur->next->val)) {
            ListNode* old = cur->next;
            cur->next = old->next;
            free(old);

        }
        cur = cur->next;
    }

    return head;
}