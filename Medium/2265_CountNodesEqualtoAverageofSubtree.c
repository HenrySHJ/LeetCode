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

typedef struct { 
    int sum; 
    int n; 
} TreeSum;

int ans;

TreeSum traverse(TreeNode* root) {
    TreeSum l = (TreeSum){0};
    TreeSum r = (TreeSum){0};

    if (root->left)
        l = traverse(root->left); 
    
    if (root->right)
        r = traverse(root->right); 
    
    TreeSum result = (TreeSum){l.sum + r.sum + root->val, l.n + r.n + 1};

    ans += (result.sum / result.n) == root->val;
    return result;
}

int averageOfSubtree(TreeNode* root) {
    ans = 0;

    if (root)
        traverse(root); 

    return ans;
}