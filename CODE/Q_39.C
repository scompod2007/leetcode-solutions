#include <stdlib.h>
#include <string.h>

static void makeCombination(int* candidates, int candidatesSize, int target, int idx,
                            int* comb, int combSize, int total,
                            int*** res, int* returnSize, int** returnColumnSizes, int* capacity) {
    if (total == target) {
        // Expand result arrays if capacity reached
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = (int**)realloc(*res, (*capacity) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }

        // Allocate and copy current combination
        (*res)[*returnSize] = (int*)malloc(combSize * sizeof(int));
        memcpy((*res)[*returnSize], comb, combSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = combSize;
        (*returnSize)++;
        return;
    }

    if (total > target || idx >= candidatesSize) {
        return;
    }

    // Include candidates[idx]
    comb[combSize] = candidates[idx];
    makeCombination(candidates, candidatesSize, target, idx, comb, combSize + 1,
                    total + candidates[idx], res, returnSize, returnColumnSizes, capacity);

    // Skip candidates[idx] (backtrack)
    makeCombination(candidates, candidatesSize, target, idx + 1, comb, combSize,
                    total, res, returnSize, returnColumnSizes, capacity);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int capacity = 16;

    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    // The maximum possible depth is target / min(candidates[i]), bounded safely by target
    int* comb = (int*)malloc((target + 1) * sizeof(int));

    makeCombination(candidates, candidatesSize, target, 0, comb, 0, 0,
                    &res, returnSize, returnColumnSizes, &capacity);

    free(comb);
    return res;
}