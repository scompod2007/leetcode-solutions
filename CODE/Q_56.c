#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Comparator for qsort: sorts primarily by start time, secondarily by end time
static int cmpIntervals(const void* a, const void* b) {
    const int* intervalA = *(const int**)a;
    const int* intervalB = *(const int**)b;
    
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] < intervalB[0] ? -1 : 1;
    }
    if (intervalA[1] != intervalB[1]) {
        return intervalA[1] < intervalB[1] ? -1 : 1;
    }
    return 0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (intervalsSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmpIntervals);

    // Bounded allocation: at most intervalsSize intervals can exist in the result
    int** ans = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= end) {
            end = MAX(end, intervals[i][1]);
        } else {
            // Commit merged interval [start, end]
            ans[*returnSize] = (int*)malloc(2 * sizeof(int));
            ans[*returnSize][0] = start;
            ans[*returnSize][1] = end;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;

            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Commit the final interval
    ans[*returnSize] = (int*)malloc(2 * sizeof(int));
    ans[*returnSize][0] = start;
    ans[*returnSize][1] = end;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    return ans;
}