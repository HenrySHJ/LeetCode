
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

void merge(ListNode** lists, int start, int mid, int end) {
    ListNode* LHead = lists[start];
    ListNode* RHead = lists[mid + 1];

    ListNode dummy;
    dummy.next = NULL;
    ListNode* prev = &dummy;

    while (LHead && RHead) {
        if (LHead->val < RHead->val) {
            prev->next = LHead;
            LHead = LHead->next;            
        }    
        else {
            prev->next = RHead;
            RHead = RHead->next;
        }
        prev = prev->next;
    }

    if (LHead) prev->next = LHead;
    else prev->next = RHead;
    
    lists[start] = dummy.next;
}

void mergeList(ListNode** lists, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeList(lists, start, mid);
    mergeList(lists, mid + 1, end);
    merge(lists, start, mid, end);
}

ListNode* mergeKLists(ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    mergeList(lists, 0, listsSize - 1);
    return lists[0];
}