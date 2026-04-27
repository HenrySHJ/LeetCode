# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode ListNode;

ListNode* swapPairs(ListNode* head) {
    ListNode dummy;
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* cur = head;

    while (cur && cur->next) {
        prev->next = cur->next;
        cur->next = cur->next->next;
        prev->next->next = cur;

        prev = cur;
        cur = cur->next;
    }

    return dummy.next;
}