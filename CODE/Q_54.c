int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = matrixColSize[0] - 1;

    int total = matrixSize * matrixColSize[0];
    int* spiral = (int*)malloc(sizeof(int) * total);
    int idx = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            spiral[idx++] = matrix[top][i];
        top++;

        for (int j = top; j <= bottom; j++)
            spiral[idx++] = matrix[j][right];
        right--;

        if (top <= bottom) {
            for (int k = right; k >= left; k--)
                spiral[idx++] = matrix[bottom][k];
            bottom--;
        }

        if (left <= right) {
            for (int l = bottom; l >= top; l--)
                spiral[idx++] = matrix[l][left];
            left++;
        }
    }

    *returnSize = idx;
    return spiral;
}