/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    
    int maxLeft = maxDepth(root->left);
    int maxRight = maxDepth(root->right);
    
    return MAX(maxLeft, maxRight) + 1;
}