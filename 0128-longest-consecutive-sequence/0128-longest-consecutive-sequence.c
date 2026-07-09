#include <stdlib.h>

// Hàm so sánh cho qsort
int compare(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    // Dùng < và > để so sánh thay vì trừ trực tiếp (tránh lỗi tràn số âm/dương)
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    // Bước 1: Sắp xếp mảng (O(N log N))
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxLength = 1;
    int currentLength = 1;
    
    // Bước 2: Duyệt mảng đã sắp xếp để đếm chuỗi
    for (int i = 1; i < numsSize; i++) {
        // Nếu số hiện tại trùng với số trước đó, bỏ qua (không đếm thêm)
        if (nums[i] == nums[i - 1]) {
            continue;
        }
        
        // Nếu số hiện tại liên tiếp với số trước đó
        if (nums[i] == nums[i - 1] + 1) {
            currentLength++;
        } else {
            // Nếu bị đứt đoạn, cập nhật kỷ lục và reset bộ đếm
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 1; // Reset lại về 1 cho chuỗi mới
        }
    }
    
    // Đừng quên cập nhật lần cuối khi vòng lặp kết thúc
    if (currentLength > maxLength) {
        maxLength = currentLength;
    }
    
    return maxLength;
}