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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;

    else if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
        return false; 

    else if (p->val != q->val)
        return false;

    if (!isSameTree(p->left, q->left))
        return false;

    if (!isSameTree(p->right, q->right))
        return false;

    return true;
}