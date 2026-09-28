#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    bool zeroInFirstCol = false;

    // Pass 1: Mark zeros in first row and first column
    for (int row = 0; row < m; row++) {
        if (matrix[row][0] == 0) {
            zeroInFirstCol = true;
        }
        for (int col = 1; col < n; col++) {
            if (matrix[row][col] == 0) {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    // Pass 2: Fill inner cells based on marks in first row and column
    for (int row = 1; row < m; row++) {
        for (int col = 1; col < n; col++) {
            if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                matrix[row][col] = 0;
            }
        }
    }

    // Pass 3: Zero out the first row if matrix[0][0] was marked
    if (matrix[0][0] == 0) {
        for (int col = 0; col < n; col++) {
            matrix[0][col] = 0;
        }
    }

    // Pass 4: Zero out the first column if zeroInFirstCol is true
    if (zeroInFirstCol) {
        for (int row = 0; row < m; row++) {
            matrix[row][0] = 0;
        }
    }
}