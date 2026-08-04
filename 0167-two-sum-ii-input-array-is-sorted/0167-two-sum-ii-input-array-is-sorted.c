#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // Cấp phát mảng 2 phần tử để trả về kết quả
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int left = 0;
    int right = numbersSize - 1;
    
    // Kẹp hai con trỏ từ 2 đầu mảng
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        
        if (sum == target) {
            // Mảng đầu vào 1-indexed (đánh số từ 1) nên phải cộng thêm 1
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } 
        else if (sum < target) {
            // Tổng quá nhỏ -> Cần số lớn hơn -> Tiến left
            left++;
        } 
        else {
            // Tổng quá lớn -> Cần số nhỏ hơn -> Lùi right
            right--;
        }
    }
    
    return result;
}