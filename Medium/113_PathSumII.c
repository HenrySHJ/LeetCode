#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

// Global Variables
int capacity;
int** ans;
int a_idx;

int path[1001];
int p_idx;

void dfs(TreeNode* root, int targetSum, int curSum, int** returnColumnSizes) {
    if (root == NULL) return;

    // Update information
    curSum += root->val;
    path[p_idx++] = root->val;

    // Checking if leaf node
    if (root->left == NULL && root->right == NULL) {
        if (curSum == targetSum) {
            // Dynamic array reallocation
            if (a_idx >= capacity) {
                capacity *= 2;
                ans = (int**)realloc(ans, capacity * sizeof(int*));
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
            }

            // Deep copy path
            int* curPath = (int*)malloc(p_idx * sizeof(int));
            for (int i = 0; i < p_idx; i++) 
                curPath[i] = path[i];

            // Set answer
            ans[a_idx] = curPath;
            (*returnColumnSizes)[a_idx] = p_idx;
            a_idx++;
        }
    } 
    // dfs tree nodes
    else {
        dfs(root->left, targetSum, curSum, returnColumnSizes);
        dfs(root->right, targetSum, curSum, returnColumnSizes);
    }
    p_idx--;
}

int** pathSum(TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    capacity = 64;
    a_idx = 0;
    p_idx = 0;

    ans = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    dfs(root, targetSum, 0, returnColumnSizes);
    *returnSize = a_idx;

    return ans;
}