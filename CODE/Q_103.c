#include <stdlib.h>
#include <stdbool.h>

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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (!root) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Dynamic capacity for the levels array
    int capacity = 32;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // Array-based FIFO queue for BFS (LeetCode trees typically <= 2000 nodes)
    int queueCap = 2048;
    struct TreeNode** queue = (struct TreeNode**)malloc(queueCap * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;

    // Enqueue root
    queue[tail++] = root;
    bool leftToRight = true;

    while (head < tail) {
        int size = tail - head;

        // Resize output containers when full
        if (*returnSize >= capacity) {
            capacity *= 2;
            result = (int**)realloc(result, capacity * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
        }

        int* row = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[head++];

            // Place value from left-to-right or right-to-left
            int index = leftToRight ? i : (size - 1 - i);
            row[index] = node->val;

            if (node->left) {
                queue[tail++] = node->left;
            }
            if (node->right) {
                queue[tail++] = node->right;
            }
        }

        // Toggle direction for the next level
        leftToRight = !leftToRight;

        result[*returnSize] = row;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
    }

    free(queue);
    return result;
}