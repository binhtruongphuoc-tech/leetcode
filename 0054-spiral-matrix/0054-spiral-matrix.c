
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;
    int index = 0;
    
    while (top <= bottom && left <= right) {
        // Traverse Right
        for (int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        
        // Traverse Down
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        
        // Traverse Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        // Traverse Up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    return result;
}