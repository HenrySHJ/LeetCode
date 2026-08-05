# include <stdio.h>
# include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

int max(int a, int b) {
    if (a <= b) return b;
    else return a;
}
int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}