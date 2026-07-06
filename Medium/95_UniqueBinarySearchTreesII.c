#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* clone_tree(TreeNode* root, int offset) {
    if (root == NULL) return NULL;
    
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->val = root->val + offset;
    new_node->left = clone_tree(root->left, offset);
    new_node->right = clone_tree(root->right, offset);
    
    return new_node;
}

TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* count = (int*)calloc((n + 1), sizeof(int));
    count[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            count[i] += count[j - 1] * count[i - j];
        }
    }

    TreeNode*** dp = (TreeNode***)malloc((n + 1) * sizeof(TreeNode**));
    
    dp[0] = (TreeNode**)malloc(sizeof(TreeNode*));
    dp[0][0] = NULL;

    for (int i = 1; i <= n; i++) {
        dp[i] = (TreeNode**)malloc(count[i] * sizeof(TreeNode*));
        int idx = 0;

        for (int j = 1; j <= i; j++) {
            int left_len = count[j - 1];
            int right_len = count[i - j];

            for (int l = 0; l < left_len; l++) {
                for (int r = 0; r < right_len; r++) {
                    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
                    root->val = j;
                    root->left = clone_tree(dp[j - 1][l], 0);
                    root->right = clone_tree(dp[i - j][r], j);

                    dp[i][idx++] = root;
                }
            }
        }
    }

    *returnSize = count[n];
    return dp[n];
}