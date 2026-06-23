
int largestRectangleArea(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int max_area = 0;

    for (int i = 0; i <= n; i++) {
        int current_height = (i == n) ? 0 : heights[i];
        
        while (top != -1 && current_height < heights[stack[top]]) {
            int h = heights[stack[top--]]; 
            

            int w = (top == -1) ? i : (i - stack[top] - 1);
            
            int area = h * w;
            if (area > max_area) {
                max_area = area;
            }
        }
        stack[++top] = i;
    }
    
    free(stack);
    return max_area;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL) {
        return 0;
    }
    
    int cols = matrixColSize[0];
    int* heights = (int*)calloc(cols, sizeof(int));
    int max_rectangle = 0;
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0; 
            }
        }
        
        int current_area = largestRectangleArea(heights, cols);
        if (current_area > max_rectangle) {
            max_rectangle = current_area;
        }
    }
    
    free(heights);
    return max_rectangle;
}