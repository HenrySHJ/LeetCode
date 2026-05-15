# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

int getHeight(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;

    int LH = getHeight(root->left);
    int RH = getHeight(root->right);
    int diff = LH - RH;

    if (diff < -1 || diff > 1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}