# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 0;

    ListNode* temp = head;
    while (temp) {
        temp = temp->next;
        length += 1;
    }

    ListNode* old = head;
    ListNode* prev = head;
    for (int i = 1; i <= length - n; i++) {
        prev = old;
        old = old->next;
    }

    if (old == head) {
        head = head->next;
        free(old);
        return head;
    }
    prev->next = old->next;
    free(old);
    return head;
}