#include <stdlib.h>

// Comparator for qsort
static int cmp(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0; // Avoid integer overflow from (arg1 - arg2)
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort the input array in ascending order
    qsort(nums, numsSize, sizeof(int), cmp);

    // Initial capacity for dynamic reallocation
    int capacity = 64;
    int** res = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        // Optimization: smallest sum exceeds 0, no valid triplets remain
        if (nums[i] > 0) {
            break;
        }

        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0) {
                k--;
            } else if (total < 0) {
                j++;
            } else {
                // Grow output buffer if full
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    res = (int**)realloc(res, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Allocate triplet
                res[*returnSize] = (int*)malloc(3 * sizeof(int));
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[j];
                res[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                j++;
                // Skip duplicates for the second element
                while (j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                k--;
                // Skip duplicates for the third element
                while (j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }
    }

    return res;
}