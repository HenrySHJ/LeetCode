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

TreeNode* invertTree(TreeNode* root) {
    if (!root)
        return NULL;

    invertTree(root->left);
    invertTree(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}
