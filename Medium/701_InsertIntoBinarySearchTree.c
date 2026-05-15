# include <stdio.h>
# include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* cur = root;
    TreeNode* prev = NULL;

    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;

    while (cur) {
        prev = cur;
        if (val < cur->val) cur = cur->left;
        else cur = cur->right;
    }

    if (prev == NULL) return newNode;

    if (val < prev->val) prev->left = newNode;
    else prev->right = newNode;

    return root;
}