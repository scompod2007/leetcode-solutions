#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper to count the total nodes in the tree
static int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Inorder traversal writing directly into the pre-allocated array
static void inorder(struct TreeNode* node, int* res, int* idx) {
    if (!node) return;
    
    inorder(node->left, res, idx);
    res[(*idx)++] = node->val;
    inorder(node->right, res, idx);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = countNodes(root);
    
    if (*returnSize == 0) {
        return NULL;
    }

    int* res = (int*)malloc((*returnSize) * sizeof(int));
    int idx = 0;
    
    inorder(root, res, &idx);
    
    return res;
}