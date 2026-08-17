# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

int dfs(TreeNode* root, bool isLeft) {
    if (!root)
        return 0;

    if (!root->left && !root->right) {
        if (isLeft)
            return root->val;
        return 0;
    }

    return dfs(root->left, true) + dfs(root->right, false);
}
int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
}
