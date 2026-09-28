#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper to allocate and initialize a new tree node
static struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

static struct TreeNode* build(int* preorder, int* preIndex, int* inorder, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return NULL;
    }

    // The next element in preorder traversal is always the root of the current subtree
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct TreeNode* root = createNode(rootVal);

    // Find the position of rootVal in the inorder array
    int inIndex = inStart;
    while (inIndex <= inEnd && inorder[inIndex] != rootVal) {
        inIndex++;
    }

    // All elements to the left of inIndex belong to the left subtree
    root->left = build(preorder, preIndex, inorder, inStart, inIndex - 1);

    // All elements to the right of inIndex belong to the right subtree
    root->right = build(preorder, preIndex, inorder, inIndex + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }

    int preIndex = 0;
    return build(preorder, &preIndex, inorder, 0, inorderSize - 1);
}