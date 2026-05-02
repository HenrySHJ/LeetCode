# include <stdio.h>
# include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getTreeSize(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

void fill(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    fill(root->left, arr, index);
    fill(root->right, arr, index);
    arr[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int size = getTreeSize(root);
    *returnSize = size;

    int* result = (int *)malloc(sizeof(int) * size);
    int index = 0;
    fill(root, result, &index);
    return result;
}