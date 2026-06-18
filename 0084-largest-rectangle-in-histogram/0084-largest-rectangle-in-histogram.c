#include <stdlib.h>

// Macro hỗ trợ tìm giá trị lớn nhất
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1; 
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {

        int currentHeight = (i == heightsSize) ? 0 : heights[i];


        while (top != -1 && currentHeight < heights[stack[top]]) {
            int h = heights[stack[top--]];
            

            int w = (top == -1) ? i : (i - stack[top] - 1);
            
            maxArea = MAX(maxArea, h * w);
        }
        
        stack[++top] = i;
    }

    free(stack);
    
    return maxArea;
}