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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == NULL)
        return false;
    
    if (root->left == NULL && root->right == NULL && root->val == targetSum)

    targetSum -= root->val;

    return (hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum));
}