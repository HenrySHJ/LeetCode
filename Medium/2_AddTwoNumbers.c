# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = (ListNode *)malloc(sizeof(ListNode));
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p3 = l3;
    int carry = 0;

    while (p1 || p2 || carry) {
        int temp = carry;
        if (p1) {
            temp += p1->val;
            p1 = p1->next;
        }
        if (p2) {
            temp += p2->val;
            p2 = p2->next;
        }

        carry = temp / 10;
        p3->val = temp % 10;

        if (p1 || p2 || carry) {
            p3->next = (ListNode *)malloc(sizeof(ListNode));
            p3 = p3->next;
        } 
        else {
            p3->next = NULL;
        }
    }

    return l3;
}
