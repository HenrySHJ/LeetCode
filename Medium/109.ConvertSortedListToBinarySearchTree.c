# include <stdio.h>
# include <stdlib.h>

struct ListNode { 
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct ListNode ListNode;
typedef struct TreeNode TreeNode;

int getLength(ListNode* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next; 
    }
    return length;
}

TreeNode* createTreeNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;

    int length = getLength(head);
    if (length == 0) return NULL;

    if (length == 1) 
        return createTreeNode(head->val);

    ListNode* prev = NULL;
    ListNode* mHead = head;

    int count = 0;
    while (count < length / 2) {
        count++;
        prev = mHead;
        mHead = mHead->next;
    }

    ListNode* rHead = mHead->next;
    TreeNode* root = createTreeNode(mHead->val);
    
    if (prev)
        prev->next = NULL;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(rHead);
    
    return root;
}