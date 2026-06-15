#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max_area = 0;

    // Continue until the two pointers meet
    while (left < right) {
        // Calculate the area with the current left and right lines
        int current_width = right - left;
        int current_height = MIN(height[left], height[right]);
        int current_area = current_width * current_height;
        
        // Update max_area if we found a larger container
        max_area = MAX(max_area, current_area);

        // Move the pointer pointing to the shorter line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}