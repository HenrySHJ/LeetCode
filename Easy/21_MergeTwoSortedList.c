# include <stdio.h>
# include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

typedef struct ListNode ListNode;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* prev1 = list1;
    ListNode* prev2 = list2;

    if (cur2 == NULL) return cur1;
    else if (cur1 == NULL) return cur2;
    
    ListNode* start;
    if (cur1->val <= cur2->val) start = cur1;
    else start = cur2;

    while (cur1 && cur2) {
        if (cur1->val <= cur2->val) {
            while (cur1 && cur1->val <= cur2->val) {
                prev1 = cur1;
                cur1 = cur1->next;
            }
            prev1->next = cur2;
        }
        else {
            while (cur2 && cur2->val <= cur1->val) {
                prev2 = cur2;
                cur2 = cur2->next;
            }
            prev2->next = cur1;
        }
    }

    return start;
}