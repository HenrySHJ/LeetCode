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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num2 > num1);
}

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int capacity = 8;
    int count = 0;
    int* cp = (int*)malloc(capacity * sizeof(int));

    ListNode* prev = NULL;
    ListNode* cur = head;
    int index = 1;
    while (cur) {
        if (prev && cur->next) {
            if (prev->val > cur->val && cur->val < cur->next->val) 
                cp[count++] = index;
            
            else if (prev->val < cur->val && cur->val > cur->next->val) 
                cp[count++] = index;
            
            if (count >= capacity) {
                capacity *= 2;
                cp = (int*)realloc(cp, capacity * sizeof(int));
            }
        }

        index++;
        prev = cur;
        cur = cur->next;
    }

    int* ans = (int*)malloc(2 * sizeof(int));

    if (count <= 1) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    qsort(cp, count, sizeof(int), compare);
    int maxDist = cp[count - 1] - cp[0];
    int minDist = index;
    for (int i = 1; i < count; i++) {
        if (minDist > cp[i] - cp[i - 1]) {
            minDist = cp[i] - cp[i - 1];
        }
    }

    free(cp);
    ans[0] = minDist;
    ans[1] = maxDist;
    return ans;
}
