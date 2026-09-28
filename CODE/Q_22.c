#include <stdlib.h>
#include <string.h>

static void dfs(int openP, int closeP, int n, char* current, int idx, 
                char*** res, int* returnSize, int* capacity) {
    if (openP == n && closeP == n) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *res = (char**)realloc(*res, (*capacity) * sizeof(char*));
        }

        (*res)[*returnSize] = (char*)malloc((2 * n + 1) * sizeof(char));
        memcpy((*res)[*returnSize], current, 2 * n + 1);
        (*returnSize)++;
        return;
    }

    if (openP < n) {
        current[idx] = '(';
        dfs(openP + 1, closeP, n, current, idx + 1, res, returnSize, capacity);
    }

    if (closeP < openP) {
        current[idx] = ')';
        dfs(openP, closeP + 1, n, current, idx + 1, res, returnSize, capacity);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    int capacity = 16;
    char** res = (char**)malloc(capacity * sizeof(char*));

    // Fixed buffer of size 2*n + 1 (including null terminator)
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    dfs(0, 0, n, current, 0, &res, returnSize, &capacity);

    free(current);
    return res;
}