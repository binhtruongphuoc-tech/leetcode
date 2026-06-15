int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    
    if (numsSize == 0) {
        return result;
    }
    
    int left = 0;
    int right = numsSize - 1;
    int first = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            first = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (first == -1) {
        return result;
    }
    
    left = 0;
    right = numsSize - 1;
    int last = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            last = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    result[0] = first;
    result[1] = last;
    
    return result;
}