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

int ans;
int count;

void inOrder(TreeNode* root, int k) {
    if (!root)
        return;

    inOrder(root->left, k);
    
    count++;
    if (count == k) {
        ans = root->val;
        return;
    }
    

    if (count < k)
        inOrder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    count = 0;
    inOrder(root, k);

    return ans;
}
