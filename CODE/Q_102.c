#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Capacity management for returned levels
    int capacity = 32;
    int** ans = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // Array-based FIFO queue for BFS
    // LeetCode binary trees have at most 2000 nodes
    int queueCap = 2048;
    struct TreeNode** queue = (struct TreeNode**)malloc(queueCap * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;

    // Enqueue root
    queue[tail++] = root;

    while (head < tail) {
        int levelCount = tail - head; // Number of nodes at the current level

        // Expand dynamic level containers if needed
        if (*returnSize >= capacity) {
            capacity *= 2;
            ans = (int**)realloc(ans, capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
        }

        int* levelValues = (int*)malloc(levelCount * sizeof(int));

        for (int i = 0; i < levelCount; i++) {
            struct TreeNode* curr = queue[head++];
            levelValues[i] = curr->val;

            if (curr->left) {
                queue[tail++] = curr->left;
            }
            if (curr->right) {
                queue[tail++] = curr->right;
            }
        }

        ans[*returnSize] = levelValues;
        (*returnColumnSizes)[*returnSize] = levelCount;
        (*returnSize)++;
    }

    free(queue);
    return ans;
}