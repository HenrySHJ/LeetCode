# include <stdio.h>
# include <stdlib.h>

TreeNode* createNode(int key) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}ß

TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;

    int rootIdx = (numsSize - 1) / 2;
    TreeNode* root = createNode(nums[rootIdx]);
    
    root->left = sortedArrayToBST(nums, (numsSize - 1) / 2);
    root->right = sortedArrayToBST(nums + rootIdx + 1, numsSize / 2);    
    return root; 
}