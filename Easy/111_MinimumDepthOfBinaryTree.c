# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if (l == 0 || r == 0)
        return l + r + 1;
    return min(l, r) + 1;
}