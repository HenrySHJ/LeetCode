# include <stdio.h>
# include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* cur = root;
    TreeNode* prev = NULL;

    while (cur && cur->val != key) {
        prev = cur;
        if (key < cur->val) cur = cur->left;
        else if (key > cur->val) cur = cur->right;
        else break;
    }
    if (cur == NULL) return root;

    if (cur->left == NULL && cur->right == NULL) {
        if (prev != NULL) {
            if (prev->left == cur) prev->left = NULL;
            else prev->right = NULL;
        }
        else root = NULL;
    }
    else if (cur->left == NULL || cur->right == NULL) {
        TreeNode* child;
        if (cur->left != NULL) child = cur->left;
        else child = cur->right;

        if (prev != NULL) {
            if (prev->left == cur) prev->left = child; 
            else prev->right = child;
        }
        else root = child;
    }
    else {
        TreeNode* succ_prev = cur;
        TreeNode* succ = cur->left;

        while (succ->right != NULL) {
            succ_prev = succ;
            succ = succ->right;
        }

        cur->val = succ->val;
        if (succ_prev->left == succ) succ_prev->left = succ->left;
        else succ_prev->right = succ->left;

        cur = succ;
    }

    free(cur);
    return root;
}