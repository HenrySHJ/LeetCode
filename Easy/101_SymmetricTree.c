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

bool isMirror(TreeNode* n1, TreeNode* n2) {
    if (n1 == NULL && n2 == NULL) 
        return true;
    else if (n1 == NULL || n2 == NULL)
        return false;

    return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n2->left, n1->right);
}
bool isSymmetric(TreeNode* root) {
    return isMirror(root->left, root->right);
}
