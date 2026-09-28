#include <stdbool.h>
#include <string.h>

static bool backtrack(char** board, int m, int n, int i, int j, const char* word, int k) {
    // Successfully matched all characters in word
    if (word[k] == '\0') {
        return true;
    }

    // Boundary check and character mismatch check
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
        return false;
    }

    // Mark current cell as visited
    char temp = board[i][j];
    board[i][j] = '\0';

    // Explore 4 adjacent directions: down, up, right, left
    bool found = backtrack(board, m, n, i + 1, j, word, k + 1) ||
                 backtrack(board, m, n, i - 1, j, word, k + 1) ||
                 backtrack(board, m, n, i, j + 1, word, k + 1) ||
                 backtrack(board, m, n, i, j - 1, word, k + 1);

    // Restore the cell (backtrack)
    board[i][j] = temp;

    return found;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int m = boardSize;
    int n = boardColSize[0];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (backtrack(board, m, n, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}