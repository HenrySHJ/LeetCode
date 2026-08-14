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

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* cur = head;
    ListNode* prev = NULL;
    ListNode* start = head;
    ListNode* tempPrev = NULL;
    bool startFound = false;

    while (cur) {
        int t = k;
        
        ListNode* now = cur;
        ListNode* temp = cur;
        bool flag = false;
        
        for (int i = 0; i < t; i++) {
            if (temp == NULL) {
                flag = true;
                break;
            }
            temp = temp->next;
        }

        if (flag) break;

        while (t--) {
            temp = now->next;
            now->next = prev;
            prev = now;
            now = temp;
        }

        if (!startFound) {
            start = prev;
            startFound = true;
        }
        else
            tempPrev->next = prev;
        
        tempPrev = cur;
        cur->next = now;
        cur = cur->next;
    }

    return start;
}
