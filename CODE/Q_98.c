#include <stdbool.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool valid(struct TreeNode* node, long minimum, long maximum) {
    if (!node) {
        return true;
    }

    // Node must strictly satisfy: minimum < node->val < maximum
    if (node->val <= minimum || node->val >= maximum) {
        return false;
    }

    return valid(node->left, minimum, node->val) && 
           valid(node->right, node->val, maximum);
}

bool isValidBST(struct TreeNode* root) {
    return valid(root, LONG_MIN, LONG_MAX);
}