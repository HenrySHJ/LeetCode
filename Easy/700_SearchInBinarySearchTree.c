# include <stdio.h>
# include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode* searchBST(TreeNode* root, int val) {
    while (root) {
        if (val < root->val) root = root->left;
        else if (val > root->val) root = root->right;
        else return root;
    }
    return root;
}