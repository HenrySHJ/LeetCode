# include <stdio.h>
# include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct {
    int not_rob;
    int rob;
} RobResult;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode TreeNode;

RobResult robHelper(TreeNode* root) {
    if (!root) {
        RobResult empty = {0, 0};
        return empty;
    }

    RobResult left = robHelper(root->left);
    RobResult right = robHelper(root->right);

    RobResult res;
    
    res.not_rob = max(left.not_rob, left.rob) + max(right.not_rob, right.rob);
    res.rob = root->val + left.not_rob + right.not_rob;

    return res;
}

int rob(TreeNode* root) {
    RobResult result = robHelper(root);
    return max(result.not_rob, result.rob);
}