# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = NULL;

    ListNode* cur = head;

    while (cur != NULL) {
        ListNode* nextNode = cur->next;

        ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < cur->val) {
            prev = prev->next;
        }

        cur->next = prev->next;
        prev->next = cur;

        cur = nextNode;
    }

    ListNode* sortedHead = dummy->next;
    free(dummy);

    return sortedHead;
}