int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int val = 1;
    while (val <= n * n) {
        for (int i = left; i <= right; i++) {
            matrix[top][i] = val++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = val++;
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = val++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = val++;
            }
            left++;
        }
    }
    return matrix;
}
