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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Creating new tree node
TreeNode* createNode() {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode** allPossibleFBT(int n, int* returnSize) {
    // Cant make Full binary tree with even n
    if (n % 2 == 0) {
        *returnSize = 0;
        return NULL;    
    }

    // Initialize dp table
    TreeNode*** dp = (TreeNode***)malloc((n + 1) * sizeof(TreeNode**));
    int count[n + 1];
    memset(count, 0, sizeof(count));
    
    // Set base case
    dp[1] = (TreeNode**)malloc(sizeof(TreeNode*));
    dp[1][count[1]++] = createNode();

    // Tabulation : i for total node
    for (int i = 3; i < n + 1; i += 2) {
        int capacity = 8;
        dp[i] = (TreeNode**)malloc(capacity * sizeof(TreeNode*));
        
        // j for left subtree count
        for (int l = 1; l < i; l += 2) {
            int r = i - l - 1;
            for (int c1 = 0; c1 < count[l]; c1++) {
                for (int c2 = 0; c2 < count[r]; c2++) {
                    if (count[i] >= capacity) {
                        capacity *= 2;
                        dp[i] = (TreeNode**)realloc(dp[i], capacity * sizeof(TreeNode*));
                    }

                    TreeNode* root = createNode();
                    root->left = dp[l][c1];
                    root->right = dp[r][c2]; 
                    dp[i][count[i]++] = root;
                }
            }
        }
    }
    *returnSize = count[n];
    return dp[n];

}